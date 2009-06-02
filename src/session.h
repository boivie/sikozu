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

#include <map>
#include <stdint.h>
#include <netinet/in.h>
#include <boost/smart_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include "contact.h"
#include "common.h"

namespace Sikozu {

class Session {
 public:
  void send(Command_t command, const std::vector<char>& message) const;
  static boost::shared_ptr<Session> create_incoming(ContactPtr contact_p, Channel_t channel, uint32_t sid);
  static boost::shared_ptr<Session> create_outgoing(ContactPtr contact_p, Channel_t channel);
  ContactPtr get_contact() const { return m_contact_p; }
 protected:
  Session(ContactPtr contact_p, Channel_t channel, uint32_t sid) : m_contact_p(contact_p), m_channel(channel), m_sid(sid) {}
  ContactPtr m_contact_p;
  Channel_t m_channel;
  uint32_t m_sid;
  typedef std::map<uint32_t, boost::weak_ptr<Session> > SessionMapping;
  static boost::mutex shared_mutex;
  static SessionMapping s_sessions;
  static uint32_t s_last_used_sid;
};

typedef boost::shared_ptr<Session> SessionPtr;

}
#endif
