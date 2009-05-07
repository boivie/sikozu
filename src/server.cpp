/*
 *  server.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "server.h"
#include "packet.h"
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

void Server::send_udp(Client* client_p, Packet* packet_p)
{
  vector<char>* buffer_p = packet_p->get_buffer();
  sendto(m_udp_socket, &(*buffer_p)[0], buffer_p->size(), 0, (struct sockaddr*)client_p->get_client_address(), sizeof(struct in6_addr));  
}


void got_packet(int fd, short event, void* arg) 
{
  int len;
  vector<char>* buffer_p = new vector<char>(65536);
  struct sockaddr_in6 from;
  socklen_t l = sizeof(from);

  printf("DNS_read called with %s fd: %d, event: %d\n", event_get_method(), fd, event);

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
  
  // The packet now has custody of the buffer, and will free it when necessary
  Packet* packet_p = new Packet(&buffer_p);
  
  if (!packet_p->is_valid())
    return;
    
  Client* client_p = new Client();
  client_p->set_client_address(&from);

  Server* server_p = Server::get_instance();
  ServiceRegistry& sr = server_p->get_service_registry();
  Service* service_p = sr.get_service(packet_p->get_header()->get_channel());
  service_p->handle_request(client_p, packet_p);
}

int Server::listen_udp(uint16_t port)
{
  struct sockaddr_in si_me;
  
  if ((m_udp_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    return 0;

  fcntl(m_udp_socket, F_SETFL, O_NONBLOCK);
  
  memset((char *) &si_me, 0, sizeof(si_me));
  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(port);
  si_me.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(m_udp_socket, (const sockaddr*)&si_me, sizeof(si_me))==-1)
    return 0;
  
  struct event ev;
  event_set(&ev, m_udp_socket, EV_READ|EV_PERSIST, got_packet, &ev);
  event_add(&ev, NULL);
}