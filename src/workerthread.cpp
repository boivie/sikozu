/*
 *  workerthread.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <boost/thread.hpp>
#include <iostream> 
#include "workerthread.h"
#include "server.h"

using namespace std;
using namespace Sikozu;
using namespace boost;

static mutex thread_starter;

void WorkerThread::start() 
{
  mutex::scoped_lock(thread_starter);
  wt_call wt(this);
  m_me = boost::thread(wt);
}

void WorkerThread::thread_main()
{
  {
    mutex::scoped_lock(thread_starter);
  }
  Server* server_p = Server::get_instance();
  cout << "Started thread " << m_id << " (" << (m_me.get_id()) << ")" << endl;
  
  while (true)
  {
    PacketHeader ph;
    
    // May block here.
    auto_ptr<RawRequest> raw_p = server_p->get_incoming_request();
    
    ph.parse(&raw_p->buffer[0], raw_p->buffer_size);
    if (!ph.valid())
    {
      // Bad packet, drop.
      cerr << "Header validation failed, dropping packet." << endl;
      return;
    }
 
    ContactPtr contact_p = Contact::get(raw_p->from);

    size_t payload_size = raw_p->buffer_size - ph.size();
    auto_ptr<vector<char> > payload_p(new vector<char>(payload_size));
    if (payload_size > 0)
      memcpy(&(*payload_p)[0], &raw_p->buffer[ph.size()], payload_size);

    auto_ptr<Request> request_p(new Request(ph, contact_p, payload_p));
  
    ServiceRegistry& sr = server_p->get_service_registry();
    Service* service_p = sr.get_service(ph.get_channel());
    if (service_p != NULL)
    {
      cout << "[" << m_id << "] Dispatching packet to service: " << service_p->get_name() << endl;
      service_p->handle_request(request_p);
    }
    else
    {
      cerr << "No service found." << endl;
    } 
  }
}