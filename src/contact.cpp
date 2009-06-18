/*
 *  contact.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "common.h"
#include <boost/thread/mutex.hpp>

using namespace Sikozu;
using namespace std;
using namespace boost;

ContactRegistry::Mapping ContactRegistry::s_instances;
boost::mutex ContactRegistry::instance_mutex;

ContactPtr ContactRegistry::get(const struct sockaddr_in6& address)
{ 
  ContactRegistryKey key(address);
  {
    mutex::scoped_lock l(instance_mutex);
    ContactRegistry::Mapping::iterator i = s_instances.find(key);
    if (i != s_instances.end())
    {
      if (ContactPtr contact_p = i->second.lock())
      {
        return contact_p;
      }
    }
    
    // Not here. Have to create one and insert it.
    ContactPtr contact_p(new Contact(address));
    s_instances.insert(std::make_pair(key, weak_ptr<Contact>(contact_p)));
    return contact_p;
  }
}

ContactPtr ContactRegistry::create_new(const NodeId& nodeid) 
{
  Contact* object_p = new Contact(nodeid);
  return ContactPtr(object_p);
}

void ContactRegistry::remove(const struct sockaddr_in6& address)
{
  ContactRegistryKey key(address);
  mutex::scoped_lock l(instance_mutex);
  s_instances.erase(key);
}
ContactRegistryKey::ContactRegistryKey(const struct sockaddr_in6& address)
{
  memcpy(&m_key[0],  &address.sin6_addr, 16);
  memcpy(&m_key[16], &address.sin6_port, 2);
}

bool ContactRegistryKey::operator < (const ContactRegistryKey& n1) const
{
  return memcmp(n1.m_key, m_key, sizeof(n1.m_key));
}


Contact::~Contact() 
{
  if (m_has_addr)
  {
    // Also remove it from the table of all instances
    ContactRegistry::remove(this->m_caddr);
  }
}
