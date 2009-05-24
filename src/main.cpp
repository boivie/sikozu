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
#include <dlfcn.h>

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
  
  list<string> external_services;
  
  external_services.push_back("simpledb");
  
  for (list<string>::iterator i = external_services.begin(); i != external_services.end(); ++i)
  {
    string dlname = "./xcode/build/Debug/lib" + *i + ".dylib";
    cout << "Loading: " << dlname << endl;
    void* handle = dlopen(dlname.c_str(), RTLD_LAZY);
    if (!handle) 
    {
      cerr << "Cannot open library: " << dlerror() << '\n';
      return 1;
    }
    typedef Service* (*create_t)(Server*);

    // reset errors
    dlerror();
    create_t create_service_p = (create_t) dlsym(handle, "create_service");
    const char *dlsym_error = dlerror();
    if (dlsym_error) 
    {
      cerr << "Cannot load symbol 'create_service': " << dlsym_error << endl;
      dlclose(handle);
      return 1;
    }
      
    sr.register_service(create_service_p(server_p));
  }
  
  // Run main loop
  cout << "Executing main loop." << endl;
  event_dispatch();
  
  cout << "Exiting..." << endl;
  return 0;
}
