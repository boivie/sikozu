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


void Task::wait()
{
  bool again = true;
  Event* event_p;
  boost::system_time timeout;
  
  while (again)
  {
    timers.get_next_timeout(timeout);
    if (m_queue.wait_and_pop_timed(event_p, timeout)
    {
      if (event_p->is_transaction_reply())
      {
        if (OutboundTransactionRegistry::wake_up(event_p->contact_p, 
          again = false;
      }
    }
  
    // Timeout transactions, if any
    for (;;)
    {
      TimerInfoPtr info_p;
      
      if (timers.get_first_expired(info_p))
      {
        
        again = false;
      }
      else
      {
        break;
      }
    }
  }  
}