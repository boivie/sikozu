/*
 *  timer.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-27.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef TIMER_H_INCLUSION_GUARD
#define TIMER_H_INCLUSION_GUARD

#include <queue>
#include <vector>
#include <boost/thread/thread_time.hpp>
#include <boost/thread/mutex.hpp>
#include "baseevent.h"

namespace Sikozu {

  class TimerInfo {
  public:
    boost::system_time m_abs_timeout;
    void* m_clientdata;
    bool m_active;
  };
  
  typedef boost::shared_ptr<TimerInfo> TimerInfoPtr;

  class Timer : public Event {
  public:
    Timer();
    Timer(int milliseconds);
    bool operator==(const Timer& other) const { return m_timer_info_p == other.m_timer_info_p; }
    void restart(int milliseconds);
    void cancel();    
    virtual bool is_timer() const { return true; }
   protected:
    TimerInfoPtr m_timer_info_p;
  };
  

  class TimerComparator {
  public:
    bool operator()(const TimerInfoPtr& lhs, const TimerInfoPtr& rhs) const {
      return (lhs->m_abs_timeout < rhs->m_abs_timeout);
    } 
  };  

  class ThreadTimers {
  public:
    boost::system_time get_next_timeout();
    TimerInfoPtr get_first_expired();
  protected:
    friend class Timer;
    void add_timer(TimerInfoPtr timer_p);
    void remove_timer(TimerInfoPtr timer_p);
    std::priority_queue< TimerInfoPtr, std::vector<TimerInfoPtr>, TimerComparator > m_future_timers;
  };
  
}


#endif