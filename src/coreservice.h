/*
 *  coreservice.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CORE_SERVICE_H_INCLUSION_GUARD
#define CORE_SERVICE_H_INCLUSION_GUARD 

#include <memory>
#include "service.h"
 
namespace Sikozu {

  class CoreService : public Service {
  public:
    const char* get_short_name() { return "core"; };
    const char* get_long_name() { return "Sikozu Core"; };
    void handle_request(std::auto_ptr<Request> request_p);
  protected:
    void handle_ping(std::auto_ptr<Request> request_p);
    void handle_get_services(std::auto_ptr<Request> request_p);
    void handle_find_node(std::auto_ptr<Request> request_p);
    void handle_announce_service(std::auto_ptr<Request> request_p);
    void handle_get_channel(std::auto_ptr<Request> request_p);
  };
}

#endif
