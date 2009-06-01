/*
 *  event.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-01.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef EVENT_H_INCLUSION_GUARD
#define EVENT_H_INCLUSION_GUARD
namespace Sikozu {
  class Event {
    virtual bool is_timer() { return false; }
    virtual bool is_request() { return false; }
    virtual bool is_raw_request() { return false; }
  };
}
#endif
