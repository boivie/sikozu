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
#include "baseservice.h"
#include "thread.h"

namespace Sikozu {
  class CoreServiceThread : public Thread {
   public:
    void thread_main();
  };

  class CoreService : public BaseService {
  public:
    CoreService(NodeId& mynid); 
    const std::string& get_name() const;
    void handle_request(std::auto_ptr<Request> request_p);
  protected:
    void handle_ping(Request& request);
    void handle_get_services(Request& request);
    void handle_find_node(Request& request);
    void handle_announce_service(Request& request);
    void handle_get_channel(Request& request);
    CoreServiceThread m_thread;
  };
}

#endif
