/*
 *  task.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-12.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "task.h"
#include "transaction.h"


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

Task::Task()
{
}

BlockableTask::~BlockableTask()
{
  // Have to clear the event queue manually.
  for (;;)
  {
    TransactionReply* event_p;
    if (!m_queue.try_pop(event_p))
      break;
    delete event_p;
  }
}


void BlockableTask::post_event(auto_ptr<TransactionReply> event_p)
{
  // auto_ptr doesn't work good in STL containers, so we have to be very careful instead
  // and handle the deletion of the objects manually.
  m_queue.push(event_p.release());
}


void BlockableTask::wait()
{
  bool again = true;
  boost::system_time timeout;
  
  while (again)
  {
    m_transactions.get_next_timeout(timeout);
    TransactionReply* eventRaw_p;
    if (m_queue.wait_and_pop_timed(eventRaw_p, timeout))
    {
      auto_ptr<TransactionReply> reply_p(eventRaw_p);
      try 
      {
        m_transactions.wake_up(reply_p);
        again = false;
      } 
      catch (TransactionNotFoundException& ex)
      {
      }
    }
  
    // Timeout transactions, if any
    if (m_transactions.timeout_transactions())
    {
      again = false;
    }
  }  
}

void Task::run(boost::shared_ptr<Task> me_p)
{
  // We keep a shared_ptr-reference to ourselves while we run. We have to pass it 
  // to whoever calls ::current(), so that's why. We remove the reference as soon
  // as we have finished executing.
  m_me_p = me_p; 
  task_main(); 
  m_me_p.reset(); 
}