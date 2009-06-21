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
#include <boost/thread/mutex.hpp>


namespace Sikozu {
  class ServerException : public std::exception {};
  class Server;
  
  struct ScheduledTask {
    struct event event;
    boost::shared_ptr<Task> task_p;
    struct timeval delay;
    bool is_new;
    Server* server_p;
  };
  
  struct PacketToSend {
    ContactPtr contact_p;
    std::vector<char>* data_p;
  };

  class Server {
    public:
      Server(int workers = 4);
      ~Server();
      static Server* get_instance() { return m_instance; };
      const NodeId& get_nodeid() const { return nid; }
      ServiceRegistry& get_service_registry() { return m_serviceregistry; };
      void send_udp(ContactPtr contact_p, std::auto_ptr<std::vector<char> > buffer_p);
      int listen_udp(uint16_t port);
      void on_packet(int fd);
      void on_ipc(int fd);
      void on_timer(ScheduledTask* taskinfo_p);
      void schedule(std::auto_ptr<Task> task_p);
      void schedule_at(std::auto_ptr<Task> task_p, struct timeval& delay);
      void run();
            
    protected:
      boost::mutex timer_mutex;
      boost::mutex packet_mutex;
      
      int m_write_pipe;
      std::list<ScheduledTask*> m_timers;
      std::queue<PacketToSend> m_packets;
      boost::threadpool::pool m_thread_pool;
      static Server* m_instance;
      ServiceRegistry m_serviceregistry;
      int m_udp_socket;
      NodeId nid;
      struct event m_ev;
      struct event m_pipe;
  };
}
#endif
