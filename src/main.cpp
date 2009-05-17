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

using namespace Sikozu;
using namespace std;

int main(int argc, char **argv)
{
  event_init();
    
  // Register services.
  Server* server_p = Server::get_instance();
  ServiceRegistry& sr = server_p->get_service_registry();
  sr.register_service(0, new CoreService());
  
  // Start listening socket
  Server::get_instance()->listen_udp(9081);
  
  // Run main loop
  cout << "Executing main loop." << endl;
  event_dispatch();
  
  cout << "Exiting..." << endl;
  return 0;
}
