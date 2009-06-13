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
#include "event.h"
#include "timer.h"
#include "cqueue.h"

namespace Sikozu {

  class Task {
   public:
    virtual void task_main() = 0;
    void post_event(std::auto_ptr<Event> event_p);
    void run(boost::shared_ptr<Task> me_p) { m_me_p = me_p; task_main(); m_me_p.reset(); }
    ~Task();
    /** Waits for one event, then returns. */
    void wait();
    ThreadTimers timers;
    static boost::shared_ptr<Task> current();
   protected:
    concurrent_queue< Event* > m_queue;
    boost::shared_ptr<Task> m_me_p; // Only available during task_main
    static boost::thread_specific_ptr<Task> current_p;
  };

  class TaskEventRegistry {
   public:
    static uint32_t register_id();
    static boost::shared_ptr<Task> unregister_id(uint32_t id);
    static void cleanup();
   private:
    std::map<uint32_t, boost::shared_ptr<Task> > s_mapping;
  };


}

#endif 