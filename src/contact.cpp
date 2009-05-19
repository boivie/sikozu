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

using namespace Sikozu;
using namespace std;

  typedef std::map<std::vector<char>, Contact*> ContactMapping_t;
  static ContactMapping_t s_instances;


static void make_key(struct sockaddr_in6& address, vector<char>& key)
{
  memcpy(&key[0], &address.sin6_addr, 16);
  memcpy(&key[16], &address.sin6_port, 2);
}

ContactPtr Contact::get(struct sockaddr_in6& address)
{
  vector<char> key(16 + 2);
  make_key(address, key);
  ContactMapping_t::iterator i = s_instances.find(key);
  Contact* object_p;
  if (i == s_instances.end())
  {
    object_p = new Contact(address);
    s_instances[key] = object_p;
  }
  else
  {
    object_p = (*i).second;
  }
  return ContactPtr(object_p);
}

ContactPtr Contact::create_new(NodeId& nodeid) 
{
  Contact* object_p = new Contact(nodeid);
  return ContactPtr(object_p);
}

Contact::~Contact() 
{
  // Also remove it from the table of all instances
  vector<char> key(16 + 2);
  make_key(this->m_caddr, key);
  s_instances.erase(key);
}
