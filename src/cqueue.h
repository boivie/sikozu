/*
 *  queue.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CQUEUE_H_INCLUSION_GUARD
#define CQUEUE_H_INCLUSION_GUARD

#include <queue>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

namespace Sikozu {

template<typename Data>
class concurrent_queue
{
private:
    std::queue<Data> the_queue;
    boost::mutex the_mutex;
    boost::condition_variable the_condition_variable;
public:
    void push(Data const& data)
    {
        boost::mutex::scoped_lock lock(the_mutex);
        the_queue.push(data);
        lock.unlock();
        the_condition_variable.notify_one();
    }

    bool empty() const
    {
        boost::mutex::scoped_lock lock(the_mutex);
        return the_queue.empty();
    }

    bool try_pop(Data& popped_value)
    {
        boost::mutex::scoped_lock lock(the_mutex);
        if(the_queue.empty())
        {
            return false;
        }
        
        popped_value=the_queue.front();
        the_queue.pop();
        return true;
    }

    bool wait_and_pop_timed(Data& popped_value, boost::system_time& timeout)
    {
        boost::mutex::scoped_lock lock(the_mutex);
        while(the_queue.empty())
        {
            if (!the_condition_variable.timed_wait(lock, timeout))
            {
              return false;
            }
        }
        
        popped_value=the_queue.front();
        the_queue.pop();
        return true;
    }

};

}
#endif