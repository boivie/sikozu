/*
 *  task.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-11.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TASK_H_INCLUSION_GUARD
#define TASK_H_INCLUSION_GUARD

#include <memory>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include "event.h"
#include "timer.h"
#include "cqueue.h"
#include "transaction.h"

namespace Sikozu {

  class TaskNotFoundException : public std::exception {};

  class Task {
   public:
    virtual void task_main() = 0;
    void post_event(std::auto_ptr<TransactionReply> event_p);
    void run(boost::shared_ptr<Task> me_p) { m_me_p = me_p; task_main(); m_me_p.reset(); }
    ~Task();
    /** Waits for one event, then returns. */
    void wait();
    static boost::shared_ptr<Task> current();
    ActiveOutboundTransactions m_transactions;
   protected:
    concurrent_queue< TransactionReply* > m_queue;
    boost::shared_ptr<Task> m_me_p; // Only available during task_main
    static boost::thread_specific_ptr<Task> current_p;
  };

}

#endif 