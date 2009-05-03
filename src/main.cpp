#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <err.h>
#include <event.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <fcntl.h>

using namespace std;

void diep(char *s)
{
  cout << s << endl;
  exit(1);
}

void got_packet(int fd, short event, void* arg) 
{
  int len;
 	char *buf = (char*)malloc(255);
  socklen_t l = sizeof(struct sockaddr);
  struct sockaddr_in cAddr;

  printf("DNS_read called with %s fd: %d, event: %d\n", event_get_method(), fd, event);

  len = recvfrom(fd, buf, 254, 0, (struct sockaddr*)&cAddr, &l);

  if (len == -1)
  {
    cout << "recvfrom()" << endl;
    return;
  } else if (len == 0) {
    cout << "Connection Closed" << endl;
    return;
  }
  buf[len] = '\0';

  printf("READ: %s\n", buf);
}

int main(int argc, char **argv)
{
  struct sockaddr_in si_me;
  int s;

  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    diep("socket");

  fcntl(s, F_SETFL, O_NONBLOCK);
  
  memset((char *) &si_me, 0, sizeof(si_me));
  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(9080);
  si_me.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(s, (const sockaddr*)&si_me, sizeof(si_me))==-1)
    diep("bind");



  event_init();
  struct event ev;
  event_set(&ev, s, EV_READ|EV_PERSIST, got_packet, &ev);
  event_add(&ev, NULL);
  event_dispatch();
  cout << "Exiting..." << endl;
  return 0;
}
