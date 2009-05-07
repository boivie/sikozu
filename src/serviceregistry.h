/*
 *  serviceregistry.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-07.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#include "service.h"
#include <stdint.h>

namespace Sikozu {
  class ServiceRegistry {
   public:
    Service* get_service(uint32_t channel);
    void register_service(uint32_t channel, Service* service_p);
    
   private:
    std::vector<Service*> m_services;
    Service m_default_service;
  };
}