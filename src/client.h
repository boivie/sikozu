/*
 *  client.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CLIENT_H_INCLUSION_GUARD
#define CLIENT_H_INCLUSION_GUARD

#include <netinet/in.h>
#include "nodeid.h"

namespace Sikozu {
class Client {
 public:
  Client() {};
  NodeId& get_nodeid() { return m_nodeid; }
  struct sockaddr_in6& get_address() { return m_caddr; };
 private:
  NodeId m_nodeid;
  struct sockaddr_in6 m_caddr;
};

}

#endif
