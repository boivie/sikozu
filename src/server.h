/*
 *  server.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SERVER_H_INCLUSION_GUARD
#define SERVER_H_INCLUSION_GUARD

#include "nodeid.h"
#include "serviceregistry.h"
#include <stdint.h>
#include <vector>

namespace Sikozu {
  class Server {
    public:
      static Server* get_instance() { if (m_instance == 0) m_instance = new Server(); return m_instance; };
      NodeId& get_nid() { return nid; }
      ServiceRegistry& get_service_registry() { return m_serviceregistry; };
      void send_udp(Client* client_p, std::vector<char>* data_p);
      int listen_udp(uint16_t port);
      
    protected:
      Server() {};
      static Server* m_instance;
      ServiceRegistry m_serviceregistry;
      int m_udp_socket;
      NodeId nid;
  };
}
#endif
