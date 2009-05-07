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
#include <iostream>
#include <google/protobuf/io/zero_copy_stream_impl.h>

namespace Sikozu {

using namespace std;
using namespace google::protobuf::io;

enum CommandIdentifier {
  PING_REQUEST, PING_RESPONSE,
  FIND_NODE_REQUEST, FIND_NODE_RESPONSE,
  GET_SERVICES_REQUEST, GET_SERVICES_RESPONSE,
  
  LAST
};

void CoreService::handle_request(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  cout << "Got command: " << header_p->get_command() << ", ";
  
  switch (header_p->get_command())
  {
  case PING_REQUEST:
  {
    cout << "PING";
    header_p->set_command(PING_RESPONSE);
    header_p->set_nid(Server::get_instance()->get_nid());
    buffer_p->resize(40);
    ArrayOutputStream out(&(*buffer_p)[0], buffer_p->size());
    header_p->serialize(&out);
    buffer_p->resize(out.ByteCount());
    Server::get_instance()->send_udp(client_p, buffer_p);
    break;
  }
  default:
    cout << "<unknown>";
    break;
  }
  cout << endl;
  
  delete client_p;
  delete header_p;
  delete buffer_p;
}

}