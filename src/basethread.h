/*
 *  basethread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

/*
 *  basethread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

/*
 *  workerthread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BASE_THREAD_H_INCLUSION_GUARD
#define BASE_THREAD_H_INCLUSION_GUARD

#include <memory>
#include <boost/thread.hpp>
#include "cqueue.h"
#include "request.h"
#include "thread.h"

namespace Sikozu {
  class BaseThread : public Thread {
   public:
    BaseThread() {}
    virtual void start();
    virtual void thread_main() = 0;
    
    virtual void add_raw_request(RawRequest* request);
    
   protected:
    std::auto_ptr<Request> get_request();
    std::auto_ptr<RawRequest> get_raw_request();
    concurrent_queue< RawRequest* > m_queue;
    boost::thread m_me;
  };
  
}

#endif