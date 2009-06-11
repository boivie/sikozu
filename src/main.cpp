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
#include <boost/program_options.hpp>
#include <dlfcn.h>

//#include "simpledb.h"

using namespace Sikozu;
using namespace std;
namespace po = boost::program_options;

int main(int argc, char **argv)
{
  event_init();
  
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
      ("port", po::value<int>(), "use UDP port number")
      ("external,x", po::value< vector<string> >(), "enable external library")
      ("threads,t", po::value<int>(), "Number of worker threads to use (default: 4)")
      ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) 
  {
    cout << desc << "\n";
    return 1;
  }
  
  // Create the server, and the worker threads
  int worker_threads = (vm.count("threads")) ? vm["threads"].as<int>() : 4;
  Server* server_p = new Server(worker_threads);
      
  // Start listening socket
  uint16_t port = (vm.count("port")) ? vm["port"].as<int>() : 9081;
  server_p->listen_udp(port);
  
  // Register services - core and external
  ServiceRegistry& sr = server_p->get_service_registry();
  sr.register_service(new CoreService(server_p->get_nid()));
  
  if (vm.count("external") > 0)
  {
    const vector<string>& values = vm["external"].as<vector<string> >();
  
    for (vector<string>::const_iterator i = values.begin(); i != values.end(); ++i)
    {
      string dlname = *i;
      cout << "Loading external library: " << dlname << endl;
      void* handle = dlopen(dlname.c_str(), RTLD_LAZY);
      if (!handle) 
      {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
      }
      typedef void (*sikozu_load_t)(Server*);

      // reset errors
      dlerror();
      sikozu_load_t sikozu_load = (sikozu_load_t) dlsym(handle, "sikozu_load");
      const char *dlsym_error = dlerror();
      if (dlsym_error) 
      {
        cerr << "Cannot load symbol 'create_service': " << dlsym_error << endl;
        dlclose(handle);
        return 1;
      }
      
      sikozu_load(server_p);
    }
  }
  
  // Run main loop
  cout << "Executing main loop." << endl;
  event_dispatch();
  
  cout << "Exiting..." << endl;
  return 0;
}
