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
  try
  {
    return m_services.at(channel);
  } 
  catch(exception& except)
  {
    return &m_default_service;
  }
}
    
void ServiceRegistry::register_service(uint32_t channel, Service* service_p)
{
  if (channel >= m_services.size())
  {
    m_services.resize(channel + 1, &m_default_service);
  }
  m_services[channel] = service_p;
}
    
}