/*
 *  server.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <event.h>
#include <fcntl.h>
#include <boost/bind.hpp>
#include <unistd.h>
#include <boost/thread/mutex.hpp>
#include <google/protobuf/io/zero_copy_stream_impl.h>

#include "server.h"
#include "request.h"
#include "rawpackethandler.h"

using namespace Sikozu;
using namespace google::protobuf::io;
using namespace std;

Server* Server::m_instance = NULL;

void got_ipc(int fd, short event, void* arg) 
{
  ((Server*)arg)->on_ipc(fd);
}


Server::Server(int workers)
  : m_thread_pool(workers) 
{
  m_instance = this;
  event_init();
  
  int pipefd[2];
  if (pipe(pipefd) == -1)
  {
    throw ServerException();
  }

  m_write_pipe = pipefd[1];
  event_set(&m_pipe, pipefd[0], EV_READ|EV_PERSIST, got_ipc, this);
  event_add(&m_pipe, NULL);
}

Server::~Server()
{
  list<struct ScheduledTask*>::iterator it;
  
  for (it = m_timers.begin(); it != m_timers.end(); ++it)
  {
    delete *it;
  }
}

void Server::send_udp(ContactPtr contact_p, std::auto_ptr<vector<char> > buffer_p)
{
  PacketToSend packet;
  packet.contact_p = contact_p;
  packet.data_p = buffer_p.release();
  {
    boost::mutex::scoped_lock l(packet_mutex);
    m_packets.push(packet);
  }
  // Ask ourselves (well, the main thread) to add the timer.
  char buf[1] = {'U'};
  write(m_write_pipe, buf, 1);
}

void got_packet(int fd, short event, void* arg) 
{
  ((Server*)arg)->on_packet(fd);
}

void on_timer_cb(int fd, short event, void* arg)
{
  ScheduledTask* taskinfo_p = (ScheduledTask*)arg;
  taskinfo_p->server_p->on_timer(taskinfo_p);
}

void Server::on_packet(int fd)
{
  auto_ptr<RawRequest> raw_p(new RawRequest());
  socklen_t l = sizeof(raw_p->from);
  
  raw_p->buffer_size = recvfrom(fd, &raw_p->buffer[0], sizeof(raw_p->buffer), 0, (struct sockaddr*)&raw_p->from, &l);
  
  if (raw_p->buffer_size == -1)
  {
    cerr << "recvfrom() returned -1, no packet." << endl;
    return;
  } else if (raw_p->buffer_size == 0) {
    cerr << "Connection Closed" << endl;
    return;
  }

  auto_ptr<Task> task_p(new RawPacketHandler(raw_p));
  schedule(task_p);
}

void Server::on_timer(ScheduledTask* taskinfo_p)
{
  // Copy what we need to stay alive.
  boost::shared_ptr<Task> task_p = taskinfo_p->task_p;

  {
    boost::mutex::scoped_lock l(timer_mutex);
    // Find the expired task and delete it from the list.
    m_timers.remove(taskinfo_p);
  }
  delete taskinfo_p;
  
  m_thread_pool.schedule(boost::bind(&Task::run, task_p, task_p));
}

void Server::on_ipc(int fd)
{
  char buf[1];
  int ret = read(fd, buf, 1);
  
  if (ret == -1)
  {
    cerr << "read() return -1, IPC dead." << endl;
    return;
  }
  else if (ret == 0)
  {
    cerr << "Connection closed?" << endl;
    return;
  }
  
  if (buf[0] == 'T')
  {
    // add timer! But which one? Add any that is new and not running already.
    list<ScheduledTask*>::iterator it;
    boost::mutex::scoped_lock l(timer_mutex);
    for (it = m_timers.begin(); it != m_timers.end(); ++it)
    {
      ScheduledTask* taskinfo_p = *it;
      if (taskinfo_p->is_new)
      {
        evtimer_set(&taskinfo_p->event, on_timer_cb, taskinfo_p);
        evtimer_add(&(taskinfo_p->event), &taskinfo_p->delay);
        taskinfo_p->is_new = false;
      }
    }
  }
  else if (buf[0] == 'U')
  {
    PacketToSend packet;
    {
      boost::mutex::scoped_lock l(packet_mutex);
      packet = m_packets.front();
      m_packets.pop();
    }
    auto_ptr<std::vector<char> > data_p(packet.data_p);
    sendto(m_udp_socket, &(*data_p)[0], data_p->size(), 0, (struct sockaddr*)&packet.contact_p->get_address(), sizeof(struct sockaddr_in6));  
  } 
}

void Server::schedule(auto_ptr<Task> task_p)
{
  boost::shared_ptr<Task> n_task_p(task_p.release());

  m_thread_pool.schedule(boost::bind(&Task::run, n_task_p, n_task_p));
}

void Server::schedule_at(auto_ptr<Task> task_p, struct timeval& delay)
{
  auto_ptr<ScheduledTask> scheduled_task_p(new ScheduledTask);
  scheduled_task_p->task_p = boost::shared_ptr<Task>(task_p.release());
  scheduled_task_p->server_p = this;
  scheduled_task_p->delay = delay;
  scheduled_task_p->is_new = true;
  {
    boost::mutex::scoped_lock l(timer_mutex);
    m_timers.push_front(scheduled_task_p.release());
  }
  // Ask ourselves (well, the main thread) to add the timer.
  char buf[1] = {'T'};
  write(m_write_pipe, buf, 1);
}

int Server::listen_udp(uint16_t port)
{
  struct sockaddr_in6 si_me;
  
  if ((m_udp_socket = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP))==-1)
    return 0;

  fcntl(m_udp_socket, F_SETFL, O_NONBLOCK);
  
  memset((char *) &si_me, 0, sizeof(si_me));
#ifdef SIN6_LEN
  si_me.sin6_len = sizeof(si_me);
#endif
  si_me.sin6_family = AF_INET6;
  si_me.sin6_flowinfo = 0;
  si_me.sin6_addr = in6addr_any;
  si_me.sin6_port = htons(port);

  if (bind(m_udp_socket, (const sockaddr*)&si_me, sizeof(si_me))==-1)
    return 0;
  
  cout << "Listening on UDP port " << port << endl;
  event_set(&m_ev, m_udp_socket, EV_READ|EV_PERSIST, got_packet, this);
  event_add(&m_ev, NULL);
  return 1;
}

void Server::run()
{
  // Run main loop
  event_dispatch();
}

