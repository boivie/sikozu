/*
 *  session.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SESSION_H_INCLUSION_GUARD
#define SESSION_H_INCLUSION_GUARD

#include <stdint.h>
#include <netinet/in.h>
#include "contact.h"

namespace Sikozu {

class SessionPtr;

class Session {
 public:
  void send(uint32_t command, const std::vector<char>& message) const;
  static SessionPtr create(ContactPtr contact_p, uint32_t channel, uint32_t sid);
  ContactPtr get_contact() const { return m_contact_p; }
 protected:
  Session(ContactPtr contact_p, uint32_t channel, uint32_t sid) : m_contact_p(contact_p), m_channel(channel), m_sid(sid), count_(0) {}
  ContactPtr m_contact_p;
  uint32_t m_channel;
  uint32_t m_sid;
  friend class SessionPtr;
  int count_;  
};


class SessionPtr {
 public:
   Session* operator-> () { return p_; }
   Session& operator* ()  { return *p_; }
   SessionPtr(Session* p)    : p_(p) { ++p_->count_; }  // p must not be NULL
  ~SessionPtr()           { if (--p_->count_ == 0) delete p_; }
   SessionPtr(const SessionPtr& p) : p_(p.p_) { ++p_->count_; }
   SessionPtr& operator= (const SessionPtr& p)
         { // DO NOT CHANGE THE ORDER OF THESE STATEMENTS!
           // (This order properly handles self-assignment)
           // (This order also properly handles recursion, e.g., if a Session contains SessionPtrs)
           Session* const old = p_;
           p_ = p.p_;
           ++p_->count_;
           if (--old->count_ == 0) delete old;
           return *this;
         }
 private:
   Session* p_;    // p_ is never NULL
 }; 



}
#endif
