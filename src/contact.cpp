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

Contact::Mapping Contact::s_instances;
boost::mutex Contact::instance_mutex;

static void make_key(struct sockaddr_in6& address, vector<char>& key)
{
  memcpy(&key[0], &address.sin6_addr, 16);
  memcpy(&key[16], &address.sin6_port, 2);
}

ContactPtr Contact::get(struct sockaddr_in6& address)
{
  vector<char> key(16 + 2);
  make_key(address, key);
  {
    mutex::scoped_lock l(instance_mutex);
    Contact::Mapping::iterator i = s_instances.find(key);
    if (i != s_instances.end())
    {
      if (ContactPtr contact_p = i->second.lock())
      {
        return contact_p;
      }
      else
      {
        // The expired weak pointer will soon be overwritten again.
      }
    }
  }
  
  // Not here. Have to create one and insert it.
  ContactPtr contact_p(new Contact(address));
  {
    mutex::scoped_lock l(instance_mutex);
    s_instances[key] = weak_ptr<Contact>(contact_p);
  }
  return contact_p;
}

ContactPtr Contact::create_new(NodeId& nodeid) 
{
  Contact* object_p = new Contact(nodeid);
  return ContactPtr(object_p);
}

Contact::~Contact() 
{
  if (m_has_addr)
  {
    // Also remove it from the table of all instances
    vector<char> key(16 + 2);
    make_key(this->m_caddr, key);
    s_instances.erase(key);
  }
}
