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
#include "core.pb.h"
#include <boost/smart_ptr.hpp>
#include <boost/thread/mutex.hpp>

namespace Sikozu {

class ContactNotValidException : public std::exception {};

class Contact {
 friend class ContactRegistry;
 public:

  const NodeId& get_nodeid() const { return m_nodeid; }
  void set_nodeid(const NodeId& nid) { m_has_nid = true; m_nodeid = nid; }
  bool has_nodeid() const { return m_has_nid; }

  const struct sockaddr_in6& get_address() const { return m_caddr; }
  void set_address(const struct sockaddr_in6& addr) { m_has_addr = true; m_caddr = addr; }

  uint32_t get_timestamp() const { return m_timestamp; }
  void set_timestamp(uint32_t timestamp) { m_timestamp = timestamp; }

  ~Contact();

 protected:  
  Contact(const struct sockaddr_in6& address) : m_caddr(address), m_has_nid(false), m_has_addr(true) {} 
  Contact(const NodeId& nodeid) : m_nodeid(nodeid), m_has_nid(true), m_has_addr(false) {}
  NodeId m_nodeid;
  struct sockaddr_in6 m_caddr;
  uint32_t m_timestamp;
  bool m_has_nid;
  bool m_has_addr;
};

class ContactRegistryKey {
 public:
  ContactRegistryKey(const struct sockaddr_in6& address);
  bool operator < (const ContactRegistryKey& n1) const;
 private:
  uint8_t m_key[18];
};

class ContactRegistry {
friend class Contact;
public:
  static boost::shared_ptr<Contact> get(const struct sockaddr_in6& address);
  static boost::shared_ptr<Contact> create_new(const NodeId& nid);
  static boost::shared_ptr<Contact> get_from_msg(const Messages::Contact& contact_msg);
protected:
  static void remove(const struct sockaddr_in6& address);
  static boost::mutex instance_mutex;
  typedef std::map<ContactRegistryKey, boost::weak_ptr<Contact> > Mapping;
  static Mapping s_instances;
};


typedef boost::shared_ptr<Contact> ContactPtr;
}
#endif
