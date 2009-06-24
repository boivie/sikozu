/*
 *  finder.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-25.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "finder.h"
#include "core.pb.h"
#include "coreservice.h"
#include "server.h"
#include "task.h"
#include <google/protobuf/io/zero_copy_stream_impl.h>

using namespace google::protobuf::io;
using namespace Sikozu;
using namespace std;

Finder::Finder(int k, int alpha) 
  : m_k(k), m_alpha(alpha) 
{
}

NodeFinder::NodeFinder(int k, int alpha)
  : Finder(k, alpha)
{
  for (int i = 0; i < alpha; i++)
  {
    m_workers.push_back(NodeFinderWorker(this));
  }
}
Finder::~Finder()
{
}

ContactPtr Finder::get_best_unvisited()
{
  BestSoFar_t::iterator it;
  for (it = m_best_so_far.begin(); it != m_best_so_far.end(); ++it)
  {
    const ContactPtr& contact_p = *it;
    if (m_visited_nodes.find(contact_p) != m_visited_nodes.end())
      continue;

    // Found a contact. Add it to the "visited nodes list", since that what we are about to do.
    m_visited_nodes.insert(make_pair(contact_p, FINDER_PROGRESS_SENT_REQUEST));
    return contact_p;
  }
  throw NoMoreContacts();
}

void Finder::add_contact(ContactPtr contact_p)
{
  VisitedNodes_t::iterator it = m_visited_nodes.find(contact_p);
  
  if ((it != m_visited_nodes.end()) && (it->second == FINDER_PROGRESS_GOT_TIMEOUT))
  {
    // We have bad experience from this one. Don't add it.
  }
  else
  {
    // Either unknown, one we have contacted or are in the progress of contacting. Good either way.
    m_best_so_far.insert(contact_p);
  }
}

ContactPtr FinderWorker::get_best_unvisited() const
{
  return finder_p->get_best_unvisited(); 
}

void FinderWorker::add_contact(ContactPtr contact_p) const 
{ 
  finder_p->add_contact(contact_p); 
}

bool Finder::is_finished() const 
{
  int nodes_to_verify = 3;
  // Abort when we have contacted all nodes in our list, or at least a number of nodes.
  VisitedNodes_t::const_iterator visited_it;
  BestSoFar_t::const_iterator best_it = m_best_so_far.begin();

  while ((nodes_to_verify--) && (best_it != m_best_so_far.end()))
  {
    const ContactPtr contact_p = *best_it;
    visited_it = m_visited_nodes.find(contact_p);
    if (visited_it == m_visited_nodes.end()) 
    {
      // One of the top ones have not yet been visited. This is not good enough
      return false;
    }
    if (visited_it->second != FINDER_PROGRESS_GOT_RESPONSE)
    {
      // We have not yet received a response from the top ones. 
      return false;
    }
  }
  
  return true;
}

void FinderWorker::on_timeout()
{
  // Mark this contact as "bad", remove it from the list and move on.
  finder_p->m_visited_nodes[m_transaction_p->get_contact()] = FINDER_PROGRESS_GOT_TIMEOUT;
  finder_p->m_best_so_far.erase(m_transaction_p->get_contact());
  /* TODO: Tell the bucket stores that this contact should be supervised. */
  send_request();
}

void NodeFinderWorker::send_request()
{
  try {
    ContactPtr contact_p = get_best_unvisited();
    RemoteService core_service;

    // Issue the request - create a new transaction
    m_transaction_p = OutboundTransaction::create(contact_p, core_service);
    m_transaction_p->set_callback(this);

    Messages::FindNodeRequest outmsg;
    const vector<uint8_t>& nid = contact_p->get_nodeid().get_bytes();
    outmsg.set_nid(&nid[0], nid.size());
    if (((NodeFinder*)finder_p)->m_service_p->size() > 0)
      outmsg.set_service(*((NodeFinder*)finder_p)->m_service_p);
    vector<char> buffer(8192);
    ArrayOutputStream outstream(&buffer[0], buffer.size());
    outmsg.SerializeToZeroCopyStream(&outstream);
    buffer.resize(outstream.ByteCount());

    m_transaction_p->send_request(CoreService::FIND_NODE_REQUEST, buffer);
  } 
  catch (NoMoreContacts& ex) 
  {
    
  }
}

void NodeFinderWorker::on_response(Request& response)
{
  Messages::FindNodeResponse inmsg;
  const vector<char>& payload = response.get_payload();
  ArrayInputStream instream(&payload[0], payload.size());

  if (!inmsg.ParseFromZeroCopyStream(&instream))
  {
    // TODO: What to do?
  }
  else
  {
    for (int i = 0; i < inmsg.contacts_size(); i++)
    {
      try 
      {
        add_contact(ContactRegistry::get_from_msg(inmsg.contacts(i)));
      }
      catch (ContactNotValidException& ex)
      {
        // Bad data in message. We will continue with the rest of the contacts, but maybe we shouldn't?
        cerr << "Invalid contact in message" << endl;
      }
    }
  }
}

void Finder::do_find() 
{
  boost::shared_ptr<Task> task_p = Task::current();
  for (int i = 0; i < m_alpha; i++)
  {
    get_worker(i).send_request();
  }

  while (!is_finished())
  {    
    task_p->wait();
  }
}

void NodeFinder::find(const NodeId& nid, const std::string& service, const std::vector<ContactPtr>& initial, std::vector<ContactPtr>& output)
{
  m_nid_p = &nid;
  m_service_p = &service;
  
  // Copy the initial contents into our set, and start processing.
  for (vector<ContactPtr>::const_iterator it = initial.begin(); it != initial.end(); ++it)
  {
    m_best_so_far.insert(*it);
  }  

  do_find();
}
