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

#include <stdlib.h>
#include <event.h>
#include <vector>
#include <memory>
#include <stdint.h>
#include <boost/threadpool.hpp>
#include "nodeid.h"
#include "serviceregistry.h"
#include "rawpackethandler.h"
#include "cqueue.h"

namespace Sikozu {
  class Server {
    public:
      Server(int workers = 4) : m_thread_pool(workers) { m_instance = this; }
      static Server* get_instance() { return m_instance; };
      NodeId& get_nid() { return nid; }
      ServiceRegistry& get_service_registry() { return m_serviceregistry; };
      void send_udp(const struct sockaddr_in6& addr, std::vector<char>& buffer);
      int listen_udp(uint16_t port);
      void on_packet(int fd, short event, void* arg);
      void schedule(std::auto_ptr<Task> task_p);
            
    protected:
      boost::threadpool::pool m_thread_pool;
      static Server* m_instance;
      ServiceRegistry m_serviceregistry;
      int m_udp_socket;
      NodeId nid;
      struct event m_ev;
  };
}
#endif
