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

void CoreService::handle_get_services(auto_ptr<Request> request_p)
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
  
  vector<char> buffer(8192);

  ArrayOutputStream outstream(&buffer[0], buffer.size());
  msg.SerializeToZeroCopyStream(&outstream);
  buffer.resize(outstream.ByteCount());
  request_p->get_session()->send(0, GET_SERVICES_RESPONSE, buffer);

}

void CoreService::handle_ping(auto_ptr<Request> request_p)
{
  cout << "PING, PONG" << endl;
  // Here we will re-use the buffer, since the ping response signal will be exactly the same size as the 
  // ping request signal. Otherwise, we would have had to resize the buffer first.
  vector<char> pb(0);
  request_p->get_session()->send(0, PING_RESPONSE, pb);
}

void CoreService::handle_find_node(auto_ptr<Request> request_p)
{
  cout << "FIND_NODE" << endl;
}

void CoreService::handle_announce_service(auto_ptr<Request> request_p)
{
  cout << "ANNOUNCE_SERVICE" << endl;
  vector<char>& payload = request_p->get_payload();
  ArrayInputStream instream(&payload[0], payload.size());
  AnnounceServiceRequest msg;
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  
  if (msg.ParseFromZeroCopyStream(&instream))
  {
    NodeId nid(msg.nid());
    ContactPtr contact_p = request_p->get_contact();
    contact_p->set_nodeid(nid);
  
    for (int i = 0; i < msg.info_size(); i++)
    {
      const AnnounceServiceRequest_Info& info = msg.info(i);
      Service* service_p = sr.get_service(info.name());      
      if (info.provides() && service_p)
      {
        // The client provides a service we also provide. Remember that.
        service_p->add_provider(contact_p);
      }
      if (info.provides() && !service_p)
      {
        // The client provides a service we don't know anything about. Remember it in the "unknown services" fifo
        // TODO!
      }
      if (info.tracks() && service_p)
      {
        // The client wants to track a service we provide. Remember that in the "track fifo"
        service_p->add_tracker(contact_p);
      }
    }
  }
}

void CoreService::handle_request(auto_ptr<Request> request_p)
{
  switch (request_p->get_command())
  {
  case PING_REQUEST:
    handle_ping(request_p);
    break;
  case GET_SERVICES_REQUEST:
    handle_get_services(request_p);
    break;
  case FIND_NODE_REQUEST:
    handle_find_node(request_p);
    break;
  case ANNOUNCE_SERVICE:
    handle_announce_service(request_p);
    break;
  default:
    cout << "Got an unknown command: " << request_p->get_command() << endl; 
    break;
  }
}
