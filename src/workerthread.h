/*
 *  workerthread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef WORKER_THREAD_H_INCLUSION_GUARD
#define WORKER_THREAD_H_INCLUSION_GUARD

#include <memory>
#include <boost/thread.hpp>
#include "cqueue.h"
#include "request.h"

namespace Sikozu {
  class WorkerThread {
   public:
    WorkerThread(int id) : m_id(id) {}
    void start();
    void thread_main();
    
    void add_request(Request* request);
    
   protected:
    std::auto_ptr<Request> get_request();
    int m_id;
    concurrent_queue< Request* > m_queue;
    boost::thread m_me;
  };
  
  struct wt_call {
    wt_call(WorkerThread* wt) : m_wt(wt) {}
    void operator()() {  m_wt->thread_main(); }
    WorkerThread* m_wt;
  };

}

#endif