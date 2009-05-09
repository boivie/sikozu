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
#include "service.h"

namespace Sikozu {
  class DefaultService : public Service {
   public:
    const char* get_short_name() { return "default"; }
    const char* get_long_name() { return "default"; }
  };

  class ServiceRegistry {
   public:
    Service* get_service(uint32_t channel, bool default_if_missing = false);
    Service* get_service(std::string name, bool default_if_missing = false);
    void register_service(uint32_t channel, Service* service_p);
    std::map<uint32_t, Service*>* get_all_services() { return &m_services; };
    
   private:
    std::map<uint32_t, Service*> m_services;
    std::map<std::string, Service*> m_services_by_name;
    DefaultService m_default_service;
  };
}

#endif
