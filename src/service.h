/*
 *  service.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SERVICE_H_INCLUSION_GUARD
#define SERVICE_H_INCLUSION_GUARD
 
#include <vector>
#include <memory>
#include "contact.h"
#include "request.h"
#include "bucketstore.h"

namespace Sikozu {
  class Service {
   public:
    virtual ~Service() {};
    virtual const char* get_short_name() = 0;
    virtual const char* get_long_name() = 0;
    virtual void handle_request(std::auto_ptr<Request> request_p) = 0;
    virtual bool handle_find_node_request(std::auto_ptr<Request> request_p);
    virtual void add_provider(ContactPtr client_p);
    virtual void add_tracker(ContactPtr client_p);
   protected:
    BucketStore m_bucket_store;
  };
}

#endif
