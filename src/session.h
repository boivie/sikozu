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
#include "common.h"
#include <boost/smart_ptr.hpp>

namespace Sikozu {

class Session {
 public:
  void send(Command_t command, const std::vector<char>& message) const;
  static boost::shared_ptr<Session> create(ContactPtr contact_p, Channel_t channel, uint32_t sid);
  ContactPtr get_contact() const { return m_contact_p; }
 protected:
  Session(ContactPtr contact_p, Channel_t channel, uint32_t sid) : m_contact_p(contact_p), m_channel(channel), m_sid(sid) {}
  ContactPtr m_contact_p;
  Channel_t m_channel;
  uint32_t m_sid;
};

typedef boost::shared_ptr<Session> SessionPtr;

}
#endif
