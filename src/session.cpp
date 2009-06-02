/*
 *  session.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include <boost/thread/mutex.hpp>
#include "session.h"
#include "server.h"

using namespace Sikozu;
using namespace std;
using namespace boost;

Session::SessionMapping Session::s_sessions;
uint32_t Session::s_last_used_sid = 0;
boost::mutex Session::shared_mutex;

SessionPtr Session::create_incoming(ContactPtr contact_p, Channel_t channel, uint32_t sid) 
{
  return SessionPtr(new Session(contact_p, channel, sid));
}

void Session::send(Command_t command, const std::vector<char>& message) const
{
  Server* server_p = Server::get_instance();
  vector<char> buffer(message.size() + PACKET_HEADER_SIZE);
  PacketHeader ph;
  ph.set_channel(m_channel);
  ph.set_command(command);
  ph.set_sid(m_sid);
  ph.serialize(&buffer[0], PACKET_HEADER_SIZE);
  
  if (message.size() > 0)
  {
    memcpy(&buffer[PACKET_HEADER_SIZE], &message[0], message.size());
  }
  server_p->send_udp(m_contact_p->get_address(), buffer);
}

SessionPtr Session::create_outgoing(ContactPtr contact_p, Channel_t channel)
{
  uint32_t sid;
  
  mutex::scoped_lock l(shared_mutex);

  do {
    sid = ++s_last_used_sid;
  } while (s_sessions.find(sid) != s_sessions.end());
  
  SessionPtr session_p(new Session(contact_p, channel, sid));
  
  s_sessions[sid] = boost::weak_ptr<Session>(session_p);
  return session_p;
}
