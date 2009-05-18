/*
 *  serviceregistry.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-07.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <exception>
#include <iostream>
#include "serviceregistry.h"

using namespace std;

namespace Sikozu {

Service* ServiceRegistry::get_service(Channel_t channel)
{
  map<Channel_t, Service*>::iterator iter = m_services.find(channel);
  if (iter == m_services.end())
  {
    return NULL;
  }
  return iter->second;
}

Service* ServiceRegistry::get_service(string name)
{
  map<string, Service*>::iterator iter = m_services_by_name.find(name);
  if (iter == m_services_by_name.end())
  {
    return NULL;
  }
  return iter->second;
}
    
void ServiceRegistry::register_service(Service* service_p)
{
  Channel_t channel;
  // Find a matching channel number. Except for the core service, which gets channel 0 (reserved)
  if (service_p->get_name() == "core")
  {
    channel = 0;
  }
  else
  {
    assert(false);
  } 
  
  cout << "Registered Service '" << service_p->get_name() << "' at channel " << channel << "." << endl;
  service_p->set_channel(channel);
  m_services[channel] = service_p;
  m_services_by_name[service_p->get_name()] = service_p;
}

}