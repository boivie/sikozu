/*
 *  serviceregistry.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-07.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#ifndef SERVICE_REGISTRY_H_INCLUSION_GUARD
#define SERVICE_REGISTRY_H_INCLUSION_GUARD
 
#include <stdint.h>
#include <map>
#include <boost/thread/mutex.hpp>
#include <exception>
#include "service.h"

namespace Sikozu {
  class ServiceNotFoundException : public std::exception {};

  class ServiceRegistry {
   public:
    Service& get_service(Channel_t channel);
    Service& get_service(std::string name);
    void register_service(Service* service_p);
    const std::map<Channel_t, Service*> get_all_services();

   private:
    boost::mutex m_mutex;
    std::map<Channel_t, Service*> m_services;
    std::map<std::string, Service*> m_services_by_name;
  };
}

#endif
