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

namespace Sikozu {

class ContactPtr;

class Contact {
 public:

  const NodeId& get_nodeid() const { return m_nodeid; }
  void set_nodeid(const NodeId& nid) { m_nodeid = nid; }

  const struct sockaddr_in6& get_address() const { return m_caddr; }
  void set_address(const struct sockaddr_in6& addr) { m_caddr = addr; }

  uint32_t get_timestamp() const { return m_timestamp; }
  void set_timestamp(uint32_t timestamp) { m_timestamp = timestamp; }

  static ContactPtr get(struct sockaddr_in6& address);
  static ContactPtr create_new(NodeId& nid);

 protected:
  Contact(struct sockaddr_in6& address) : count_(0), m_caddr(address) {} 
  Contact() : count_(0) {}
  ~Contact();
  friend class ContactPtr;
  int count_;
  NodeId m_nodeid;
  struct sockaddr_in6 m_caddr;
  uint32_t m_timestamp;
};

class ContactPtr {
 public:
   Contact* operator-> () const { return p_; }
   Contact& operator* ()  { return *p_; }
   ContactPtr(Contact* p)    : p_(p) { ++p_->count_; }  // p must not be NULL
  ~ContactPtr()           { if (--p_->count_ == 0) delete p_; }
   ContactPtr(const ContactPtr& p) : p_(p.p_) { ++p_->count_; }
   ContactPtr& operator= (const ContactPtr& p)
         { // DO NOT CHANGE THE ORDER OF THESE STATEMENTS!
           // (This order properly handles self-assignment)
           // (This order also properly handles recursion, e.g., if a Contact contains ContactPtrs)
           Contact* const old = p_;
           p_ = p.p_;
           ++p_->count_;
           if (--old->count_ == 0) delete old;
           return *this;
         }
 private:
   Contact* p_;    // p_ is never NULL
 }; 

}
#endif
