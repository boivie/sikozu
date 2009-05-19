/*
 *  contact.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CONTACT_H_INCLUSION_GUARD
#define CONTACT_H_INCLUSION_GUARD

#include <exception>
#include <netinet/in.h>
#include <map>
#include "nodeid.h"
#include <boost/smart_ptr.hpp>

namespace Sikozu {

class Contact {
 public:

  const NodeId& get_nodeid() const { return m_nodeid; }
  void set_nodeid(const NodeId& nid) { m_nodeid = nid; }

  const struct sockaddr_in6& get_address() const { return m_caddr; }
  void set_address(const struct sockaddr_in6& addr) { m_caddr = addr; }

  uint32_t get_timestamp() const { return m_timestamp; }
  void set_timestamp(uint32_t timestamp) { m_timestamp = timestamp; }

  static boost::shared_ptr<Contact> get(struct sockaddr_in6& address);
  static boost::shared_ptr<Contact> create_new(NodeId& nid);
  ~Contact();

 protected:
  Contact(struct sockaddr_in6& address) : m_caddr(address) {} 
  Contact(NodeId& nodeid) : m_nodeid(nodeid) {}
  NodeId m_nodeid;
  struct sockaddr_in6 m_caddr;
  uint32_t m_timestamp;
};

typedef boost::shared_ptr<Contact> ContactPtr;
}
#endif
