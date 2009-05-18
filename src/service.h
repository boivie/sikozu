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
#include "common.h"

namespace Sikozu {
  class Service {
   public:
    virtual const std::string& get_name() const = 0;
    virtual void handle_request(std::auto_ptr<Request> request_p) = 0;
    virtual void find_nodes(NodeId& nodeid, std::list<ContactPtr>& contacts) = 0;
    virtual void add_provider(ContactPtr client_p) = 0;
    virtual Channel_t get_channel() const = 0;
    virtual void set_channel(Channel_t channel) = 0;
  };
}

#endif
