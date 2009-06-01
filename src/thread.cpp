/*
 *  basethread.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "thread.h"

using namespace Sikozu;
using namespace std;

static void cleanup_function(Thread* thread_p) 
{
}

boost::thread_specific_ptr<Thread> Thread::current_p(cleanup_function);

struct wt_call {
  wt_call(Thread* wt) : m_wt(wt) {}
  void operator()() { m_wt->thread_bootstrap(); }
  Thread* m_wt;
};

void Thread::thread_bootstrap() {
  Thread::current_p.reset(this);
  thread_main();
}

void Thread::start() 
{
  wt_call wt(this);
  m_me = boost::thread(wt);
}

void Thread::post_event(auto_ptr<Event> event_p)
{
  // auto_ptr doesn't work good in STL containers, so we have to be very careful instead
  // and handle the deletion of the objects manually.
  m_queue.push(event_p.get());
  event_p.release();
}


