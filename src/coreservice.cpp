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
#include <stdint.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "core.pb.h"

using namespace std;
using namespace google::protobuf::io;
using namespace Sikozu;

#include "core.pb.h"

enum CommandIdentifier {
  PING_REQUEST, PING_RESPONSE,
  FIND_NODE_REQUEST, FIND_NODE_RESPONSE,
  GET_SERVICES_REQUEST, GET_SERVICES_RESPONSE,
  ANNOUNCE_SERVICE_REQUEST, ANNOUNCE_SERVICE_RESPONSE,
  GET_CHANNEL_REQUEST, GET_CHANNEL_RESPONSE,
  LAST
};

void CoreService::handle_get_services(auto_ptr<Request> request_p)
{
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  map<uint32_t, Service*>* map_p = sr.get_all_services();
  Messages::GetServicesResponse msg;

  for (map<uint32_t, Service*>::iterator i = map_p->begin();
       i != map_p->end();
       i++)
  {
    // Don't include the core service - it's always there. 
    if (i->first != 0)
    {
      Messages::GetServicesResponse_Result* info_p = msg.add_services();
      info_p->set_channel(i->first);
      info_p->set_name(i->second->get_short_name());
    }
  }
  
  vector<char> buffer(8192);

  ArrayOutputStream outstream(&buffer[0], buffer.size());
  msg.SerializeToZeroCopyStream(&outstream);
  buffer.resize(outstream.ByteCount());
  request_p->get_session()->send(GET_SERVICES_RESPONSE, buffer);
}

void CoreService::handle_ping(auto_ptr<Request> request_p)
{
  static const vector<char> pb(0);
  request_p->get_session()->send(PING_RESPONSE, pb);
}

void CoreService::handle_find_node(auto_ptr<Request> request_p)
{
  const vector<char>& payload = request_p->get_payload();
  ArrayInputStream instream(&payload[0], payload.size());
  Messages::FindNodeRequest msg;
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  Service* service_p = this;
  
  if (msg.ParseFromZeroCopyStream(&instream))
  {
    list<ContactPtr> contacts;
    NodeId nid(msg.nid());
    if (msg.has_service())
    {
      service_p = sr.get_service(msg.service());
    }
    if (service_p != NULL)
    {
      service_p->find_nodes(nid, contacts);
    }
    
    Messages::FindNodeResponse outmsg;
    for (list<ContactPtr>::iterator i = contacts.begin(); i != contacts.end(); ++i)
    {    
      Messages::Contact* msg_contact_p = outmsg.add_contacts();
      ContactPtr contact_p = *i;
      const std::vector<uint8_t>& nid = contact_p->get_nodeid().get_nid();
      msg_contact_p->set_nid(&nid[0], nid.size());
      const struct sockaddr_in6& addr = contact_p->get_address();
      msg_contact_p->set_port(addr.sin6_port);
    }
    vector<char> buffer(8192);
    ArrayOutputStream outstream(&buffer[0], buffer.size());
    outmsg.SerializeToZeroCopyStream(&outstream);
    buffer.resize(outstream.ByteCount());
    request_p->get_session()->send(FIND_NODE_RESPONSE, buffer);
  }
}

void CoreService::handle_announce_service(auto_ptr<Request> request_p)
{
  const vector<char>& payload = request_p->get_payload();
  ArrayInputStream instream(&payload[0], payload.size());
  Messages::AnnounceServiceRequest msg;
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  
  if (msg.ParseFromZeroCopyStream(&instream))
  {
    NodeId nid(msg.nid());
    ContactPtr contact_p = request_p->get_contact();
    contact_p->set_nodeid(nid);
  
    for (int i = 0; i < msg.info_size(); i++)
    {
      const Messages::AnnounceServiceRequest_Info& info = msg.info(i);
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

void CoreService::handle_get_channel(auto_ptr<Request> request_p)
{
  const vector<char>& payload = request_p->get_payload();
  ArrayInputStream instream(&payload[0], payload.size());
  Messages::GetChannelRequest msg;
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();

  if (msg.ParseFromZeroCopyStream(&instream))
  {
    Messages::GetChannelResponse outmsg;
    Service* service_p = sr.get_service(msg.name());
    outmsg.set_channel(service_p != NULL ? service_p->get_channel() : 0xFFFF);

    vector<char> buffer(8192);
    ArrayOutputStream outstream(&buffer[0], buffer.size());
    outmsg.SerializeToZeroCopyStream(&outstream);
    buffer.resize(outstream.ByteCount());
    request_p->get_session()->send(GET_CHANNEL_RESPONSE, buffer);
  }
}


void CoreService::handle_request(auto_ptr<Request> request_p)
{
  switch (request_p->get_command())
  {
  case PING_REQUEST:
    cout << "PING" << endl;
    handle_ping(request_p);
    break;
  case GET_SERVICES_REQUEST:
    cout << "GET_SERVICES" << endl;
    handle_get_services(request_p);
    break;
  case FIND_NODE_REQUEST:
    cout << "FIND_NODE" << endl;
    handle_find_node(request_p);
    break;
  case ANNOUNCE_SERVICE_REQUEST:
    cout << "ANNOUNCE_SERVICE" << endl;
    handle_announce_service(request_p);
    break;
  case GET_CHANNEL_REQUEST:
    cout << "GET_CHANNEL" << endl;
    handle_get_channel(request_p);
    break;
  default:
    cout << "Got an unknown command: " << request_p->get_command() << endl; 
    break;
  }
}
