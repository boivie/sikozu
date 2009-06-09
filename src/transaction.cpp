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

using namespace Sikozu;
using namespace std;

OutboundTransaction::OutboundTransaction(ContactPtr contact_p, Channel_t channel)
  : m_contact_p(contact_p), m_channel(channel), m_thread(Thread::current())
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

}

Request& OutboundTransaction::get_response()
{
  return *m_response_p;
}

boost::shared_ptr<OutboundTransaction> OutboundTransaction::create(ContactPtr contact_p, const RemoteService& destination_service)
{
  return boost::shared_ptr<OutboundTransaction>();
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
  
boost::shared_ptr<OutboundTransaction> OutboundTransactionRegistry::wake_up(ContactPtr contact_p, uint32_t sid, std::auto_ptr<Request> request_p)
{
  return boost::shared_ptr<OutboundTransaction>();
}
