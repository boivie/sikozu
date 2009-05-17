/*
 *  session.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include "session.h"
#include "server.h"

using namespace Sikozu;
using namespace std;

SessionPtr Session::create(ContactPtr contact_p, uint32_t channel, uint32_t sid) 
{
  return SessionPtr(new Session(contact_p, channel, sid));
}

void Session::send(uint32_t command, std::vector<char>& message) const
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