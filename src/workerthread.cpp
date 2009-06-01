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

void WorkerThread::thread_main()
{
  Server* server_p = Server::get_instance();
  
  while (true)
  {
    PacketHeader ph;
    
    // May block here.
    auto_ptr<Event> event_p = Thread::receive();
    
    // We should only expect raw requests here.
    if (!event_p->is_raw_request())
      continue;

    RawRequest* raw_p = (RawRequest*)event_p.get();
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
    try 
    {
      Service& service = sr.get_service(ph.get_channel());
      try 
      {
        service.handle_request(request_p);
      }
      catch (...)
      {
        cerr << "Exception occured during handle_request - dropping." << endl;
      }
    }
    catch (ServiceNotFoundException& ex)
    {
      cerr << "No service found." << endl;
    } 
  }
}