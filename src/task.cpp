/*
 *  task.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "task.h"

using namespace std;
using namespace Sikozu;


static void cleanup_function(Task* task_p) 
{
}

boost::thread_specific_ptr<Task> Task::current_p(cleanup_function);


boost::shared_ptr<Task> Task::current()
{
  Task* cur_p = current_p.get();
  return cur_p->m_me_p;
}

Task::~Task()
{
  // Have to clear the event queue manually.
  for (;;)
  {
    Event* event_p;
    if (!m_queue.try_pop(event_p))
      break;
    delete event_p;
  }
}


void Task::post_event(auto_ptr<Event> event_p)
{
  // auto_ptr doesn't work good in STL containers, so we have to be very careful instead
  // and handle the deletion of the objects manually.
  m_queue.push(event_p.release());
}

/*
std::auto_ptr<Event> Thread::()
{
  bool got_event = false;
  Event* event_p;
  boost::system_time timeout;
  
  while (!got_event)
  {
    timers.get_next_timeout(timeout);
    got_event = m_queue.wait_and_pop_timed(event_p, timeout);
  
    // Timeout. Create timer events and add them to the queue, and fetch them again (easiest this way)
    for (;;)
    {
      TimerInfoPtr info_p = timers.get_first_expired();
      if (!info_p.get())
        break;
      
      m_queue.push((Event*)new Timer(info_p));
    }
  }
  return auto_ptr<Event>(event_p);
*/