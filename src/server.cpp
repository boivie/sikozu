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

#include <google/protobuf/io/zero_copy_stream_impl.h>

#include "server.h"
#include "request.h"
#include "rawpackethandler.h"

using namespace Sikozu;
using namespace google::protobuf::io;
using namespace std;

Server* Server::m_instance = NULL;

void Server::send_udp(const struct sockaddr_in6& addr, vector<char>& buffer)
{
  sendto(m_udp_socket, &buffer[0], buffer.size(), 0, (struct sockaddr*)&addr, sizeof(struct sockaddr_in6));  
}

void got_packet(int fd, short event, void* arg) 
{
  ((Server*)arg)->on_packet(fd, event, arg);
}

void Server::on_packet(int fd, short event, void* arg)
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

  boost::shared_ptr<RawPacketHandler> handler_p(new RawPacketHandler(raw_p));

  m_thread_pool.schedule(boost::bind(&RawPacketHandler::run, handler_p));
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


