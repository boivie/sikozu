/*
 *  transaction.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "transaction.h"
#include "server.h"
#include <boost/thread/mutex.hpp>


using namespace Sikozu;
using namespace std;
using namespace boost;

boost::mutex ActiveOutboundTransactions::s_mutex;
uint32_t ActiveOutboundTransactions::s_last_used_sid = 0;
ActiveOutboundTransactions::TransactionMapping ActiveOutboundTransactions::s_transactions;

OutboundTransaction::OutboundTransaction(ContactPtr contact_p, const RemoteService& remote_service, uint32_t sid)
  : m_timeout_ms(0), m_task_p(Task::current()), m_contact_p(contact_p), m_service(remote_service), m_sid(sid),
    m_callback_p(0)
{
}

void OutboundTransaction::set_timeout(int timeout_ms)
{
  m_timeout_ms = timeout_ms;
}

bool OutboundTransaction::has_timed_out() const
{
  return m_has_timed_out;
}

bool OutboundTransaction::is_pending() const 
{
  return !m_has_timed_out && m_response_p.get() == NULL;
}

void OutboundTransaction::send_request(Command_t command, const std::vector<char>& payload) 
{
  Server* server_p = Server::get_instance();
  std::auto_ptr<vector<char> > buffer_p(new vector<char>(payload.size() + PACKET_HEADER_SIZE));
  PacketHeader ph;
  ph.set_channel(m_service.get_channel());
  ph.set_command(command);
  ph.set_sid(m_sid);
  ph.serialize(&(*buffer_p)[0], PACKET_HEADER_SIZE);
  
  if (payload.size() > 0)
  {
    memcpy(&(*buffer_p)[PACKET_HEADER_SIZE], &payload[0], payload.size());
  }
  server_p->send_udp(m_contact_p, buffer_p); 
  
  // Start timer, if any
  if (m_timeout_ms > 0)
  {
    boost::system_time abs_timeout = boost::get_system_time() + boost::posix_time::milliseconds(m_timeout_ms);
    // Also, we'll have to find the task in the registry, to really get a shared pointer.
    // TODO: Is there no easier way to do this?
    try {
      boost::shared_ptr<OutboundTransaction> transaction_p = ActiveOutboundTransactions::find(m_sid);
      m_task_p->get_transactions().add_timeout(transaction_p, abs_timeout);
    } catch (TransactionNotFoundException& ex)
    {
      assert(false); // This can not happen. The transaction must be alive, and we must have it in the registry in that case.
      m_has_timed_out = true; // Fake that it has timed out.
    }
  }
}

void OutboundTransaction::set_response(std::auto_ptr<Request> response_p)
{ 
  m_response_p = response_p; 
  if (m_callback_p) m_callback_p->on_response(*response_p);
}

Request& OutboundTransaction::get_response()
{
  return *m_response_p;
}

boost::shared_ptr<OutboundTransaction> OutboundTransaction::create(ContactPtr contact_p, const RemoteService& destination_service)
{
  uint32_t sid = ActiveOutboundTransactions::get_new_sid();
  
  boost::shared_ptr<OutboundTransaction> transaction_p(new OutboundTransaction(contact_p, destination_service, sid));
  
  // Register it in the global SID registry.
  ActiveOutboundTransactions::add(transaction_p);
  
  return transaction_p;
}

OutboundTransaction::~OutboundTransaction()
{
  // TODO: This might be unnecessary in most cases - where the request has already been received. Maybe have a flag indicating 
  // if it should be done?

  // Remove from the global sid registry
  ActiveOutboundTransactions::remove(m_sid);

  // And the local timeout registry
  m_task_p->get_transactions().cleanup_orphan_timeouts();
}

void OutboundTransaction::timeout()
{
  // Only timeout if we have not already received a response.
  if (m_response_p.get() == NULL)
  {
    m_has_timed_out = true;
    if (m_callback_p) m_callback_p->on_timeout();
  }
}

InboundTransaction::InboundTransaction(ContactPtr contact_p, uint32_t sid, auto_ptr<Request> request_p) 
  : m_contact_p(contact_p), m_sid(sid), m_request_p(request_p)
{
  
}

void InboundTransaction::send_response(const std::vector<char>& payload)
{
  Server* server_p = Server::get_instance();
  auto_ptr<vector<char> > buffer_p(new vector<char>(payload.size() + PACKET_HEADER_SIZE));
  PacketHeader ph;
  ph.set_channel(0xFFFF);
  ph.set_command(0xFFFF);
  ph.set_sid(m_sid);
  ph.serialize(&(*buffer_p)[0], PACKET_HEADER_SIZE);
  
  if (payload.size() > 0)
  {
    memcpy(&(*buffer_p)[PACKET_HEADER_SIZE], &payload[0], payload.size());
  }
  server_p->send_udp(m_contact_p, buffer_p);

}

Request& InboundTransaction::get_request()
{
  return *m_request_p;
}


ContactPtr InboundTransaction::get_sender()
{
  return m_contact_p;
}

uint32_t ActiveOutboundTransactions::get_new_sid()
{
  mutex::scoped_lock l(s_mutex);
  uint32_t sid = s_last_used_sid + 1;
  s_last_used_sid = sid;
  return sid;
}

void ActiveOutboundTransactions::add(boost::shared_ptr<OutboundTransaction> transaction_p)
{
  mutex::scoped_lock l(s_mutex);
  boost::weak_ptr<OutboundTransaction> weak_p(transaction_p);
  s_transactions.insert(std::make_pair(transaction_p->get_sid(), weak_p));
}

boost::shared_ptr<Task> ActiveOutboundTransactions::get_task(uint32_t sid)
{
  mutex::scoped_lock l(s_mutex);
  
  ActiveOutboundTransactions::TransactionMapping::iterator it = s_transactions.find(sid);
  if (it == s_transactions.end())
    throw TransactionNotFoundException();

  boost:shared_ptr<OutboundTransaction> transaction_p = it->second.lock();
  
  if (transaction_p == 0)
    throw TransactionNotFoundException();  

  return transaction_p->get_task();
}

void ActiveOutboundTransactions::add_timeout(boost::shared_ptr<OutboundTransaction> transaction_p, boost::system_time& timeout)
{
  m_timeout_transactions.insert(TimeoutTransactionInfo(timeout, transaction_p));
}

boost::shared_ptr<OutboundTransaction> ActiveOutboundTransactions::find(uint32_t sid)
{
  mutex::scoped_lock l(s_mutex);
  ActiveOutboundTransactions::TransactionMapping::iterator it = s_transactions.find(sid);
  if (it == s_transactions.end())
    throw TransactionNotFoundException();

  return it->second.lock();
}

void ActiveOutboundTransactions::wake_up(std::auto_ptr<TransactionReply> reply_p)
{
  boost:shared_ptr<OutboundTransaction> transaction_p = find(reply_p->get_sid());
  
  if (transaction_p == 0)
    throw TransactionNotFoundException();  
    
  ContactPtr tr_contact_p = transaction_p->get_contact();
  
  // Verify that the response is from the same contact
  if (tr_contact_p != reply_p->get_contact())
    throw TransactionNotFoundException();
  
  {
    mutex::scoped_lock l(s_mutex);
    ActiveOutboundTransactions::s_transactions.erase(reply_p->get_sid());
  }

  // Remove timeout, if any.
  for (Timeout_Transactions_t::iterator it = m_timeout_transactions.begin(); it != m_timeout_transactions.end(); it++)
  {
    if (it->m_transaction_p.lock() == transaction_p);
    {
      m_timeout_transactions.erase(it);
      // Iterator not valid after this. But no problem - we return immediately
      break;
    }
  }

  // This will also call any callback, if present
  transaction_p->set_response(reply_p->get_request());
}

void ActiveOutboundTransactions::remove(uint32_t sid)
{
  mutex::scoped_lock l(s_mutex);
  ActiveOutboundTransactions::s_transactions.erase(sid);
}

void ActiveOutboundTransactions::get_next_timeout(boost::system_time& timeout)
{
  if (m_timeout_transactions.empty())
  {
    // Really big value.
    timeout = boost::get_system_time() + boost::posix_time::hours(24);
  } else {
    timeout = m_timeout_transactions.begin()->m_abs_timeout;
  }
}

bool ActiveOutboundTransactions::timeout_transactions()
{
  bool result = false;
  boost::system_time now = boost::get_system_time();
  Timeout_Transactions_t::iterator it;

  for (it = m_timeout_transactions.begin(); it != m_timeout_transactions.end(); it++)
  {
    if (it->m_abs_timeout < now)
    {
      boost::shared_ptr<OutboundTransaction> transaction_p = it->m_transaction_p.lock();
      assert(transaction_p != 0);
      if (transaction_p != 0) 
      {
        // Expire transaction, if it has not already received a reply
        transaction_p->timeout();
        result = true;
      }
      else
      {
        // No more transactions that have expired. 
        break;
      }
    }
  }
  // Erase the ones we've deleted.
  if (result)
    m_timeout_transactions.erase(m_timeout_transactions.begin(), it);
  return result;
}

void ActiveOutboundTransactions::cleanup_orphan_timeouts()
{
  Timeout_Transactions_t::iterator it;
  
  for (it = m_timeout_transactions.begin(); it != m_timeout_transactions.end(); )
  {
    Timeout_Transactions_t::iterator erase_it = it++;

    if (erase_it->m_transaction_p.expired()) 
    {
      m_timeout_transactions.erase(erase_it);
    }
  } 
}
