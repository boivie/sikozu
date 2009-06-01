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
#include "nodeid.h"
#include "serviceregistry.h"
#include "workerthread.h"
#include "cqueue.h"

namespace Sikozu {
  class Server {
    public:
      static Server* get_instance() { if (m_instance == 0) m_instance = new Server(); return m_instance; };
      NodeId& get_nid() { return nid; }
      ServiceRegistry& get_service_registry() { return m_serviceregistry; };
      void send_udp(const struct sockaddr_in6& addr, std::vector<char>& buffer);
      void start_workers(int count = 4);
      int listen_udp(uint16_t port);
      void on_packet(int fd, short event, void* arg);
      
      std::auto_ptr<RawRequest> get_incoming_request() { RawRequest* r; m_incoming_requests.wait_and_pop(r); return std::auto_ptr<RawRequest>(r); }
      
    protected:
      Server() : last_used_worker(0) {}
      void queue_incoming_request(RawRequest* request_p) { m_incoming_requests.push(request_p); }
      concurrent_queue<RawRequest*> m_incoming_requests;
      std::vector<WorkerThread*> m_workers;
      int last_used_worker;
      static Server* m_instance;
      ServiceRegistry m_serviceregistry;
      int m_udp_socket;
      NodeId nid;
      struct event m_ev;
  };
}
#endif
