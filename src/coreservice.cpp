/*
 *  coreservice.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "coreservice.h"
#include "server.h"
#include <google/protobuf/io/zero_copy_stream_impl.h>

namespace Sikozu {

using namespace google::protobuf::io;

enum CommandIdentifier {
  PING_REQUEST, PING_RESPONSE,
  FIND_NODE_REQUEST, FIND_NODE_RESPONSE,
  GET_SERVICES_REQUEST, GET_SERVICES_RESPONSE,
  
  LAST
};

void CoreService::handle_request(Client* client_p, Packet* packet_p)
{
  vector<char> out_buffer(65536);
  ArrayOutputStream outstream(&out_buffer[0], out_buffer.size());
  PacketHeader* ph = packet_p->get_header();
  
  switch (ph->get_command())
  {
  case PING_REQUEST:
    ph->set_command(PING_RESPONSE);
    ph->set_nid(Server::get_instance()->get_nid());
    ph->serialize(&outstream);
    break;
  }
  
  delete client_p;
  delete packet_p;
}

}