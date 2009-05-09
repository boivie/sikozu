/*
 *  server.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "server.h"
#include <google/protobuf/io/zero_copy_stream_impl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <event.h>
#include <iostream>
#include <fcntl.h>



using namespace Sikozu;
using namespace google::protobuf::io;
using namespace std;

Server* Server::m_instance = NULL;

void Server::send_udp(Client* client_p, vector<char>* buffer_p)
{
  sendto(m_udp_socket, &(*buffer_p)[0], buffer_p->size(), 0, (struct sockaddr*)&client_p->get_address(), sizeof(struct sockaddr_in6));  
}


void got_packet(int fd, short event, void* arg) 
{
  int len;
  vector<char>* buffer_p = new vector<char>(65536);
  struct sockaddr_in6 from;
  socklen_t l = sizeof(from);

  len = recvfrom(fd, &(*buffer_p)[0], buffer_p->size(), 0, (struct sockaddr*)&from, &l);

  if (len == -1)
  {
    cout << "recvfrom()" << endl;
    return;
  } else if (len == 0) {
    cout << "Connection Closed" << endl;
    return;
  }

  buffer_p->resize(len);
  
  PacketHeader* header_p = new PacketHeader();
  if (!header_p->parse(buffer_p))
    return;
   
  Client* client_p = new Client();
  client_p->get_address() = from;

  Server* server_p = Server::get_instance();
  ServiceRegistry& sr = server_p->get_service_registry();
  Service* service_p = sr.get_service(header_p->get_channel(), true);
  cout << "Using service: " << service_p->get_long_name() << endl;
  service_p->handle_request(client_p, header_p, buffer_p);
  cout << "Done." << endl;
}

int Server::listen_udp(uint16_t port)
{
  struct sockaddr_in6 si_me;
  
  if ((m_udp_socket = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP))==-1)
    return 0;

  fcntl(m_udp_socket, F_SETFL, O_NONBLOCK);
  
  memset((char *) &si_me, 0, sizeof(si_me));
  si_me.sin6_len = sizeof(si_me);
  si_me.sin6_family = AF_INET6;
  si_me.sin6_flowinfo = 0;
  si_me.sin6_addr = in6addr_any;
  si_me.sin6_port = htons(port);

  if (bind(m_udp_socket, (const sockaddr*)&si_me, sizeof(si_me))==-1)
    return 0;
  
  event_set(&m_ev, m_udp_socket, EV_READ|EV_PERSIST, got_packet, &m_ev);
  event_add(&m_ev, NULL);
  return 1;
}