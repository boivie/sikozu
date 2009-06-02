/*
 *  thread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef THREAD_H_INCLUSION_GUARD
#define THREAD_H_INCLUSION_GUARD

#include <memory>
#include "baseevent.h"
#include <boost/thread.hpp>
#include "cqueue.h"
#include "timer.h"

namespace Sikozu {
  class Thread {
   public:
    Thread() {}
    // Called by the Server when a new event is ready to be server to the thread.
    void post_event(std::auto_ptr<Event> event_p);
    // Will block the current thread until it has received an event
    static std::auto_ptr<Event> receive();
    
    void start();
    void thread_bootstrap();
    virtual void thread_main() = 0;
    static Thread& current();
    ThreadTimers timers;
  protected:
    std::auto_ptr<Event> internal_receive();
    static boost::thread_specific_ptr<Thread> current_p;
    concurrent_queue< Event* > m_queue;
    boost::thread m_me;
  };
}

#endif
