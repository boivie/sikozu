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

ContactPtr ContactRegistry::get_from_msg(const Messages::Contact& contact_msg)
{
  struct sockaddr_in6 address;
  memset(&address, 0, sizeof(address));
  if (contact_msg.has_ipv4())
  {
    uint32_t ip = contact_msg.ipv4();
    // Use ipv4 mapped ipv6 addresses.
    address.sin6_addr.s6_addr[10] = 0xFF;
    address.sin6_addr.s6_addr[11] = 0xFF;
    address.sin6_addr.s6_addr[12] = (ip >> 24) & 0xFF;
    address.sin6_addr.s6_addr[13] = (ip >> 16) & 0xFF;
    address.sin6_addr.s6_addr[14] = (ip >> 8) & 0xFF;
    address.sin6_addr.s6_addr[15] = ip & 0xFF;
  }
  else if (contact_msg.has_ipv6() && contact_msg.ipv6().size() == sizeof(address.sin6_addr))
  {
    const string& ip = contact_msg.ipv6();
    memcpy(&address.sin6_addr, ip.c_str(), sizeof(address.sin6_addr));
  }
  else
  {
    // Neither specified, or invalid ipv6 address. This is an error.
    throw ContactNotValidException();
  }

  address.sin6_port = contact_msg.port();
  ContactPtr contact_p = ContactRegistry::get(address);

  if (contact_msg.nid().size() != NID_SIZE_BYTES)
  {
    throw ContactNotValidException();
  }

  // TODO: We should perhaps verify the nodeid?
  if (!contact_p->has_nodeid())
  {
    NodeId nid(contact_msg.nid());
    contact_p->set_nodeid(nid);
  }

  return contact_p;
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
