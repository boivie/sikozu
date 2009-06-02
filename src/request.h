/*
 *  request.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-11.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef REQUEST_H_INCLUSION_GUARD
#define REQUEST_H_INCLUSION_GUARD

#include <vector>
#include <memory>
#include <utility>
#include <stdint.h>
#include "packetheader.h"
#include "session.h"
#include "contact.h"
#include "common.h"
#include "baseevent.h"

namespace Sikozu {

class RawRequest : public Event {
public:
  virtual bool is_raw_request() const { return true; }
  struct sockaddr_in6 from;
  size_t buffer_size;
  char buffer[8192];  
};

class Request : public Event {
 public:
  Request(PacketHeader& ph, ContactPtr contact_p, std::auto_ptr<std::vector<char> > payload_p);
  
  ContactPtr get_contact() const { return m_sender_p; }
  Command_t get_command() const { return m_command; }
  std::vector<char>& get_payload() { return *m_payload_p; }
  SessionPtr get_session() { return m_session_p; }
  virtual bool is_request() const { return true; }
  
 protected:
  ContactPtr m_sender_p;
  SessionPtr m_session_p;
  std::auto_ptr<std::vector<char> > m_payload_p;
  Command_t m_command;
};

}
#endif