/*
 *  thread.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef THREAD_H_INCLUSION_GUARD
#define THREAD_H_INCLUSION_GUARD

#include "basethread.h"
#include "thread.h"
#include "request.h"

namespace Sikozu {
  class Thread {
   public:
    virtual void add_raw_request(RawRequest* request) = 0;
  };
}

#endif
