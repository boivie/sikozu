/*
 *  serviceregistry.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-07.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "serviceregistry.h"
#include <exception>

using namespace std;

namespace Sikozu {

Service* ServiceRegistry::get_service(uint32_t channel)
{
  map<uint32_t, Service*>::iterator iter = m_services.find(channel);
  if (iter == m_services.end())
  {
    return &m_default_service;
  }
  return iter->second;
}
    
void ServiceRegistry::register_service(uint32_t channel, Service* service_p)
{
  m_services[channel] = service_p;
}

}