/*
 *  timer.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-27.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "timer.h"
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "thread.h"

using namespace Sikozu;
using namespace std;
using namespace boost::posix_time;

Timer::Timer() 
  : m_timer_info_p()
{
}

Timer::Timer(int ms)
  : m_timer_info_p()
{
  restart(ms);
}

void Timer::restart(int ms)
{
  // Create a new TimerInfo struct - we can't re-use the ones we have since they might be inactive timers now.
  m_timer_info_p = TimerInfoPtr(new TimerInfo());
  m_timer_info_p->m_abs_timeout = boost::get_system_time();
  m_timer_info_p->m_abs_timeout += milliseconds(ms);
  m_timer_info_p->m_active = false;
  Thread::current().timers.add_timer(m_timer_info_p);
}

void ThreadTimers::add_timer(TimerInfoPtr timer_p)
{
  timer_p->m_active = true;
  m_future_timers.push(timer_p);
}

boost::system_time ThreadTimers::get_next_timeout()
{
  for (;;)
  {
    if (m_future_timers.empty())
    {
      // No timer found. Return a really big value here.
      return boost::get_system_time() + hours(5);
    }
    
    TimerInfoPtr timer_p = m_future_timers.top();
    // Is it active? If not, drop it immediately.
    if (timer_p->m_active)
    {
      return timer_p->m_abs_timeout;
    }
    m_future_timers.pop();
  }
}

TimerInfoPtr ThreadTimers::get_first_expired()
{
  const boost::system_time now = boost::get_system_time();
  for (;;)
  {
    // No timers left?
    if (m_future_timers.empty())
    {
      return TimerInfoPtr();
    }

    TimerInfoPtr timer_p = m_future_timers.top();

    // First one hasn't expired yet?
    if (timer_p->m_abs_timeout > now)
    {
      return TimerInfoPtr();
    }
    // It has expired! Is it active?
    m_future_timers.pop();
    if (timer_p->m_active)
    {
      return timer_p;
    }
    // If not, re-iterate and drop this one.
  }
}
