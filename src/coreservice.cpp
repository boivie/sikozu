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

const string& CoreService::get_name() const {
  static const string name = "core";
  return name;
}

void CoreService::handle_get_services(auto_ptr<Request> request_p)
{
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  const map<Channel_t, Service*>& services = sr.get_all_services();
  Messages::GetServicesResponse outmsg;

  for (map<Channel_t, Service*>::const_iterator i = services.begin();
       i != services.end();
       i++)
  {
    // Don't include the core service - it's always there. 
    if (i->first != 0)
    {
      Messages::GetServicesResponse_Result* info_p = outmsg.add_services();
      info_p->set_channel(i->first);
      info_p->set_name(i->second->get_name());
    }
  }
  
  send_msg(*request_p, GET_SERVICES_RESPONSE, outmsg);
}

void CoreService::handle_ping(auto_ptr<Request> request_p)
{
  static const vector<char> pb(0);
  request_p->get_session()->send(PING_RESPONSE, pb);
}

void CoreService::handle_find_node(auto_ptr<Request> request_p)
{
  Messages::FindNodeRequest inmsg;

  parse_msg(*request_p, inmsg);

  list<ContactPtr> contacts;
  NodeId nid(inmsg.nid());
  
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  Service* service_p = this;

  if (inmsg.has_service())
  {
    service_p = sr.get_service(inmsg.service());
  }
  if (service_p != NULL)
  {
    service_p->find_nodes(nid, contacts);
  }
  // TODO: Query the ServiceNameServer
    
  Messages::FindNodeResponse outmsg;
  for (list<ContactPtr>::iterator i = contacts.begin(); i != contacts.end(); ++i)
  {    
    Messages::Contact* outmsg_contact_p = outmsg.add_contacts();
    ContactPtr contact_p = *i;
    const std::vector<uint8_t>& nid = contact_p->get_nodeid().get_nid();
    outmsg_contact_p->set_nid(&nid[0], nid.size());
    const struct sockaddr_in6& addr = contact_p->get_address();
    outmsg_contact_p->set_port(addr.sin6_port);
  }
  
  send_msg(*request_p, FIND_NODE_RESPONSE, outmsg);
}

void CoreService::handle_announce_service(auto_ptr<Request> request_p)
{
  Messages::AnnounceServiceRequest inmsg;
  
  parse_msg(*request_p, inmsg);
  
  NodeId nid(inmsg.nid());
  ContactPtr contact_p = request_p->get_contact();
  contact_p->set_nodeid(nid);
  
  // We always add nodes that provide something to the core service
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  sr.get_service("core")->add_provider(contact_p);
  
  for (int i = 0; i < inmsg.service_size(); i++)
  {
    Service* service_p = sr.get_service(inmsg.service(i));      
    if (service_p)
    {
      // The client provides a service we also provide. Remember that.
      service_p->add_provider(contact_p);
    }
    else
    {
      // The client provides a service we don't know anything about. Remember it in the "unknown services" fifo
      // TODO!
    }
  }
  Messages::AnnounceServiceResponse outmsg;
  send_msg(*request_p, ANNOUNCE_SERVICE_RESPONSE, outmsg);
}

void CoreService::handle_get_channel(auto_ptr<Request> request_p)
{
  Messages::GetChannelRequest inmsg;

  parse_msg(*request_p, inmsg);

  Messages::GetChannelResponse outmsg;

  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  Service* service_p = sr.get_service(inmsg.name());
  outmsg.set_channel(service_p != NULL ? service_p->get_channel() : SIKOZU_CHANNEL_REPLY);

  send_msg(*request_p, GET_CHANNEL_RESPONSE, outmsg);
}

void CoreService::handle_request(auto_ptr<Request> request_p)
{
  try {
    switch (request_p->get_command())
    {
    case PING_REQUEST:
//      cout << "PING" << endl;
      handle_ping(request_p);
      break;
    case GET_SERVICES_REQUEST:
//      cout << "GET_SERVICES" << endl;
      handle_get_services(request_p);
      break;
    case FIND_NODE_REQUEST:
//      cout << "FIND_NODE" << endl;
      handle_find_node(request_p);
      break;
    case ANNOUNCE_SERVICE_REQUEST:
//      cout << "ANNOUNCE_SERVICE" << endl;
      handle_announce_service(request_p);
      break;
    case GET_CHANNEL_REQUEST:
//      cout << "GET_CHANNEL" << endl;
      handle_get_channel(request_p);
      break;
    default:
      cerr << "Got an unknown command: " << request_p->get_command() << endl; 
      break;
    }
  } 
  catch (exception& e) 
  {
    cerr << "Got exception, " << e.what() << ", dropping packet." << endl;
  }
/*  catch (...)
  {
    cerr << "Got an unknown exception. Dropping packet." << endl;
  }*/
}

void CoreServiceThread::thread_main() 
{
}

CoreService::CoreService(NodeId& mynid)
  : BaseService(mynid) 
{
  // Create a thread for housekeeping. Will refresh buckets and such.
  m_thread.start();
}

