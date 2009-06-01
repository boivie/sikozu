/*
 *  workerthread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef WORKER_THREAD_H_INCLUSION_GUARD
#define WORKER_THREAD_H_INCLUSION_GUARD

#include <memory>
#include "thread.h"
#include "cqueue.h"
#include "request.h"

namespace Sikozu {
  class WorkerThread : public Thread {
   public:
    void thread_main();
  };
}

#endif