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

#include <google/protobuf/io/zero_copy_stream_impl.h>

#include "server.h"
#include "request.h"

using namespace Sikozu;
using namespace google::protobuf::io;
using namespace std;

Server* Server::m_instance = NULL;

void Server::send_udp(const struct sockaddr_in6& addr, vector<char>& buffer)
{
  sendto(m_udp_socket, &buffer[0], buffer.size(), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr_in6));  
}

static Server* callback_server = NULL;

void got_packet(int fd, short event, void* arg) 
{
  callback_server->on_packet(fd, event, arg);
}

void Server::on_packet(int fd, short event, void* arg)
{
  int len;
  RawRequest* raw_p = new RawRequest();
  socklen_t l = sizeof(raw_p->from);
  PacketHeader ph;
  
  raw_p->buffer_size = recvfrom(fd, &raw_p->buffer[0], sizeof(raw_p->buffer), 0, (struct sockaddr*)&raw_p->from, &l);
  
  if (len == -1)
  {
    cerr << "recvfrom() returned -1, no packet." << endl;
    return;
  } else if (len == 0) {
    cerr << "Connection Closed" << endl;
    return;
  }

  // Quick parse header
  ph.parse(&raw_p->buffer[0], raw_p->buffer_size);
  if (!ph.valid())
  {
    // Bad packet, drop.
    cerr << "Header validation failed, dropping packet." << endl;
    return;
  }
  
  // TODO: Check destination thread, if matching sid
  queue_incoming_request(raw_p);
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
  callback_server = this;
  event_set(&m_ev, m_udp_socket, EV_READ|EV_PERSIST, got_packet, &m_ev);
  event_add(&m_ev, NULL);
  return 1;
}


void Server::start_workers(int count)
{
  int i;
  m_workers.resize(count);
  
  // Create the workers
  cout << "Creating worker thread." << endl;
  for (i = 0; i < count; i++)
  {
    m_workers[i] = new WorkerThread();
  }
  
  // Start the workers
  cout << "Starting worker threads." << endl;
  for (i = 0; i < count; i++)
  {
    m_workers[i]->start();
  }
}

