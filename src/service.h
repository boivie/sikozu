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
 
#include <list>
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
    virtual void find_nodes(NodeId& nodeid, std::list<ContactPtr> contacts);
    virtual void add_provider(ContactPtr client_p);
    virtual void add_tracker(ContactPtr client_p);
    uint32_t get_channel() const { return m_channel; }
    void set_channel(uint32_t channel) { m_channel = channel; }
   protected:
    BucketStore m_bucket_store;
    uint32_t m_channel;
  };
}

#endif
