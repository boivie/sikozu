#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <err.h>
#include <event.h>
#include <sys/types.h>
#include <vector>
#include "server.h"
#include "coreservice.h"
//#include "simpledb.h"

using namespace Sikozu;
using namespace std;

int main(int argc, char **argv)
{
  event_init();
  Server* server_p = Server::get_instance();
  
  // Start listening socket
  server_p->listen_udp(9081);
  
  // Start worker threads
  server_p->start_workers();
  
  // Register services
  ServiceRegistry& sr = server_p->get_service_registry();
  sr.register_service(new CoreService(server_p->get_nid()));
//  sr.register_service(new SimpleDb::SimpleDbService(server_p->get_nid())); 
  
  // Run main loop
  cout << "Executing main loop." << endl;
  event_dispatch();
  
  cout << "Exiting..." << endl;
  return 0;
}
