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
#include "cqueue.h"
#include "transaction.h"

namespace Sikozu {

  class TaskNotFoundException : public std::exception {};
  class TaskNotBlockable : public std::exception {};

  class Task {
   public:
    virtual void task_main() = 0;
    void run(boost::shared_ptr<Task> me_p);
    Task();
    virtual ~Task() {}
    virtual void wait() { throw TaskNotBlockable(); }
    virtual void post_event(std::auto_ptr<TransactionReply> event_p) { throw TaskNotBlockable(); }
    virtual ActiveOutboundTransactions& get_transactions() { throw TaskNotBlockable(); }
    static boost::shared_ptr<Task> current();

   protected:
    boost::shared_ptr<Task> m_me_p; // Only available during task_main
    static boost::thread_specific_ptr<Task> current_p;
  };

  class BlockableTask : public Task {
   public:
    virtual ~BlockableTask();   
    virtual void post_event(std::auto_ptr<TransactionReply> event_p);
    virtual ActiveOutboundTransactions& get_transactions() { return m_transactions; }
    /** Waits for one event, then returns. */
    void wait();
   protected:
    concurrent_queue< TransactionReply* > m_queue;
    ActiveOutboundTransactions m_transactions;
   
  };

}

#endif 