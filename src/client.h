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

namespace Sikozu {
class Client {
 public:
  Client() {};
  void set_client_address(struct sockaddr_in6* caddr_p) { m_caddr = *caddr_p; };
  struct sockaddr_in6* get_client_address() { return &m_caddr; };
 private:
  struct sockaddr_in6 m_caddr;
};

}

#endif
