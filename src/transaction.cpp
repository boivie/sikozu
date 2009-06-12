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

boost::mutex OutboundTransactionRegistry::s_mutex;
uint32_t OutboundTransactionRegistry::s_last_used_sid = 0;
OutboundTransactionRegistry::TransactionMapping OutboundTransactionRegistry::s_transactions;

OutboundTransaction::OutboundTransaction(ContactPtr contact_p, const RemoteService& remote_service, uint32_t sid)
  : m_task_p(Task::current()), m_contact_p(contact_p), m_service(remote_service), m_sid(sid)
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
  vector<char> buffer(payload.size() + PACKET_HEADER_SIZE);
  PacketHeader ph;
  ph.set_channel(m_service.get_channel());
  ph.set_command(command);
  ph.set_sid(m_sid);
  ph.serialize(&buffer[0], PACKET_HEADER_SIZE);
  
  if (payload.size() > 0)
  {
    memcpy(&buffer[PACKET_HEADER_SIZE], &payload[0], payload.size());
  }
  server_p->send_udp(m_contact_p->get_address(), buffer); 
}

Request& OutboundTransaction::get_response()
{
  return *m_response_p;
}

boost::shared_ptr<OutboundTransaction> OutboundTransaction::create(ContactPtr contact_p, const RemoteService& destination_service)
{
  uint32_t sid = OutboundTransactionRegistry::get_sid();
  
  boost::shared_ptr<OutboundTransaction> transaction_p(new OutboundTransaction(contact_p, destination_service, sid));
  
  // Register it in the OutboundTransactionRegistry.
  OutboundTransactionRegistry::add(transaction_p);
  
  return transaction_p;
}

OutboundTransaction::~OutboundTransaction()
{
  // TODO: This might be unnecessary in most cases - where the request has already been received. Maybe have a flag indicating 
  // if it should be done?
  OutboundTransactionRegistry::remove(m_sid);
}

InboundTransaction::InboundTransaction(ContactPtr contact_p, uint32_t sid, auto_ptr<Request> request_p) 
  : m_contact_p(contact_p), m_sid(sid), m_request_p(request_p)
{
  
}

void InboundTransaction::send_response(const std::vector<char>& payload)
{
  Server* server_p = Server::get_instance();
  vector<char> buffer(payload.size() + PACKET_HEADER_SIZE);
  PacketHeader ph;
  ph.set_channel(0xFFFF);
  ph.set_command(0xFFFF);
  ph.set_sid(m_sid);
  ph.serialize(&buffer[0], PACKET_HEADER_SIZE);
  
  if (payload.size() > 0)
  {
    memcpy(&buffer[PACKET_HEADER_SIZE], &payload[0], payload.size());
  }
  server_p->send_udp(m_contact_p->get_address(), buffer);

}

Request& InboundTransaction::get_request()
{
  return *m_request_p;
}


ContactPtr InboundTransaction::get_sender()
{
  return m_contact_p;
}

uint32_t OutboundTransactionRegistry::get_sid()
{
  mutex::scoped_lock l(s_mutex);
  uint32_t sid = s_last_used_sid + 1;
  s_last_used_sid = sid;
  return sid;
}

void OutboundTransactionRegistry::add(boost::shared_ptr<OutboundTransaction> transaction_p)
{
  mutex::scoped_lock l(s_mutex);
  boost::weak_ptr<OutboundTransaction> weak_p(transaction_p);
  s_transactions.insert(std::make_pair(transaction_p->get_sid(), weak_p));
}

void OutboundTransactionRegistry::wake_up(ContactPtr contact_p, uint32_t sid, std::auto_ptr<Request> request_p)
{
  boost:shared_ptr<OutboundTransaction> transaction_p;
  
  {
    mutex::scoped_lock l(s_mutex);
    OutboundTransactionRegistry::TransactionMapping::iterator it = OutboundTransactionRegistry::s_transactions.find(sid);
    if (it == OutboundTransactionRegistry::s_transactions.end())
      throw TransactionNotFoundException();
  
    transaction_p = it->second.lock();

    // Remove it from the registry
    OutboundTransactionRegistry::s_transactions.erase(it); 
  }
  
  // We are not protected by the mutex any longer!
  if (transaction_p == NULL)
  {
    // It has already been deleted. Remove it.
    throw TransactionNotFoundException();
  }
  
  boost::shared_ptr<Task> task_p = transaction_p->get_task();
  task_p->post_event(static_cast<auto_ptr<Event> >(request_p));
}

void OutboundTransactionRegistry::remove(uint32_t sid)
{
  mutex::scoped_lock l(s_mutex);
  OutboundTransactionRegistry::s_transactions.erase(sid);
}
