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
#include "core.pb.h"

using namespace std;
using namespace google::protobuf::io;
using namespace Sikozu;
using namespace Sikozu::Messages;

#include "core.pb.h"

enum CommandIdentifier {
  PING_REQUEST, PING_RESPONSE,
  FIND_NODE_REQUEST, FIND_NODE_RESPONSE,
  GET_SERVICES_REQUEST, GET_SERVICES_RESPONSE,
  ANNOUNCE_SERVICE,
  LAST
};

void CoreService::handle_get_services(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  map<uint32_t, Service*>* map_p = sr.get_all_services();
  
  cout << "GET_SERVICES" << endl;
  
  GetServicesResponse msg;
  for (map<uint32_t, Service*>::iterator i = map_p->begin();
       i != map_p->end();
       i++)
  {
    // Don't include the core service - it's always there. 
    if (i->first != 0)
    {
      GetServicesResponse_Result* info_p = msg.add_services();
      info_p->set_channel(i->first);
      info_p->set_name(i->second->get_short_name());
    }
  }
  
  // Serialize to output
  buffer_p->resize(65536);
  header_p->set_command(GET_SERVICES_RESPONSE);
  header_p->set_nid(Server::get_instance()->get_nid());

  ArrayOutputStream outstream(&(*buffer_p)[0], buffer_p->size());
  header_p->serialize(&outstream);
  msg.SerializeToZeroCopyStream(&outstream);
  buffer_p->resize(outstream.ByteCount());
  Server::get_instance()->send_udp(client_p, buffer_p);
}

void CoreService::handle_ping(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  cout << "PING, PONG" << endl;
  // Here we will re-use the buffer, since the ping response signal will be exactly the same size as the 
  // ping request signal. Otherwise, we would have had to resize the buffer first.
  header_p->set_command(PING_RESPONSE);
  header_p->set_nid(Server::get_instance()->get_nid());
  header_p->serialize(buffer_p);
  Server::get_instance()->send_udp(client_p, buffer_p);
}

void CoreService::handle_find_node(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  cout << "FIND_NODE" << endl;
}

void CoreService::handle_announce_service(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  cout << "ANNOUNCE_SERVICE" << endl;
  ArrayInputStream instream(&(*buffer_p)[header_p->get_size()], buffer_p->size() - header_p->get_size());
  AnnounceService msg;
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  
  if (msg.ParseFromZeroCopyStream(&instream))
  {
    for (int i = 0; i < msg.info_size(); i++)
    {
      const AnnounceService_Info& info = msg.info(i);
      Service* service_p = sr.get_service(info.name());      
      if (info.provides() && service_p)
      {
        // The client provides a service we also provide. Remember that.
        service_p->add_provider(client_p);
      }
      if (info.provides() && !service_p)
      {
        // The client provides a service we don't know anything about. Remember it in the "unknown services" fifo
        // TODO!
      }
      if (info.tracks() && service_p)
      {
        // The client wants to track a service we provide. Remember that in the "track fifo"
        service_p->add_tracker(client_p);
      }
    }
  }
}

void CoreService::handle_request(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  switch (header_p->get_command())
  {
  case PING_REQUEST:
    handle_ping(client_p, header_p, buffer_p);
    break;
  case GET_SERVICES_REQUEST:
    handle_get_services(client_p, header_p, buffer_p);
    break;
  case FIND_NODE_REQUEST:
    handle_find_node(client_p, header_p, buffer_p);
    break;
  case ANNOUNCE_SERVICE:
    handle_announce_service(client_p, header_p, buffer_p);
    break;
  default:
    cout << "Got an unknown command: " << header_p->get_command() << endl; 
    break;
  }
  
  delete client_p;
  delete header_p;
  delete buffer_p;
}
