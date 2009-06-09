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
  PING_REQUEST,
  FIND_NODE_REQUEST,
  GET_SERVICES_REQUEST,
  ANNOUNCE_SERVICE_REQUEST,
  GET_CHANNEL_REQUEST,
  LAST
};

const string& CoreService::get_name() const {
  static const string name = "core";
  return name;
}

void CoreService::handle_get_services(InboundTransaction& transaction)
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
  
  send_reply(transaction, outmsg);
}

void CoreService::handle_ping(InboundTransaction& transaction)
{
  static const vector<char> pb(0);
  transaction.send_response(pb);
}

void CoreService::handle_find_node(InboundTransaction& transaction)
{
  Messages::FindNodeRequest inmsg;

  parse_request(transaction, inmsg);

  list<ContactPtr> contacts;
  NodeId nid(inmsg.nid());

  if (inmsg.has_service())
  {
    ServiceRegistry& sr = Server::get_instance()->get_service_registry();
    try 
    {
      Service& service = sr.get_service(inmsg.service());
      service.find_nodes(nid, contacts);
    }
    catch (ServiceNotFoundException& ex)
    {
      // TODO: Query the ServiceNameServer
    }
  }
  else
  {
    find_nodes(nid, contacts);
  }
    
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
  
  send_reply(transaction, outmsg);
}

void CoreService::handle_announce_service(InboundTransaction& transaction)
{
  Messages::AnnounceServiceRequest inmsg;

  parse_request(transaction, inmsg);
  
  NodeId nid(inmsg.nid());
  ContactPtr contact_p = transaction.get_sender();
  contact_p->set_nodeid(nid);
  
  // We always add nodes that provide something to the core service

  add_provider(contact_p);
  ServiceRegistry& sr = Server::get_instance()->get_service_registry();

  for (int i = 0; i < inmsg.service_size(); i++)
  {
    try 
    {
      Service& service = sr.get_service(inmsg.service(i));      
      service.add_provider(contact_p);
    }
    catch (ServiceNotFoundException& ex)
    {
      // The client provides a service we don't know anything about. Remember it in the "unknown services" fifo
      // TODO!
    }
  }
  Messages::AnnounceServiceResponse outmsg;
  send_reply(transaction, outmsg);
}

void CoreService::handle_get_channel(InboundTransaction& transaction)
{
  Messages::GetChannelRequest inmsg;

  parse_request(transaction, inmsg);

  Messages::GetChannelResponse outmsg;

  ServiceRegistry& sr = Server::get_instance()->get_service_registry();
  try {
    outmsg.set_channel(sr.get_service(inmsg.name()).get_channel());
  } 
  catch (ServiceNotFoundException& ex) 
  {
    outmsg.set_channel(SIKOZU_CHANNEL_REPLY);
  }

  send_reply(transaction, outmsg);
}

void CoreService::on_transaction(std::auto_ptr<InboundTransaction> transaction_p)
{
  switch (transaction_p->get_request().get_command())
  {
  case PING_REQUEST:
    cout << "PING_REQUEST" << endl;
    handle_ping(*transaction_p);
    break;
  case GET_SERVICES_REQUEST:
    cout << "GET_SERVICES_REQUEST" << endl;
    handle_get_services(*transaction_p);
    break;
  case FIND_NODE_REQUEST:
    cout << "FIND_NODE_REQUEST" << endl;
    handle_find_node(*transaction_p);
    break;
  case ANNOUNCE_SERVICE_REQUEST:
    cout << "ANNOUNCE_SERVICE_REQUEST" << endl;  
    handle_announce_service(*transaction_p);
    break;
  case GET_CHANNEL_REQUEST:
    cout << "GET_CHANNEL_REQUEST" << endl;  
    handle_get_channel(*transaction_p);
    break;
  default:
    cerr << "Got an unknown command: " << transaction_p->get_request().get_command() << endl; 
    break;
  }
}

void CoreServiceThread::thread_main() 
{
#if 0
  OutboundTransactionPtr transaction_p[3];
  int i;
  
  for (i = 0; i < 3; i++)
  {
    ContactPtr contact_p;
    RemoteService service;
    transaction_p[i] = OutboundTransaction::create(contact_p, service);
    transaction_p[i]->set_timeout(3000);
  }
  
  while (transaction_p[0]->is_pending() || 
         transaction_p[1]->is_pending() || 
         transaction_p[2]->is_pending())
  {
    Thread::receive();
  }
  
#endif
}

CoreService::CoreService(NodeId& mynid)
  : BaseService(mynid) 
{
  // Create a thread for housekeeping. Will refresh buckets and such.
  m_thread.start();
}

