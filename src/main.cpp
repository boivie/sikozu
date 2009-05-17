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

extern "C" {
#ifdef USE_LUA51_PATH
# include <lua5.1/lua.h>
# include <lua5.1/lualib.h>
# include <lua5.1/lauxlib.h>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif
}

#include "server.h"
#include "coreservice.h"

using namespace Sikozu;
using namespace std;

static int listen_socket(lua_State* L)
{
  int port = luaL_checkint(L, 1);

  Server::get_instance()->listen_udp(port);

  return 0;
}

int main(int argc, char **argv)
{
  lua_State* L;
  
  event_init();
    
  // Register services.
  Server* server_p = Server::get_instance();
  ServiceRegistry& sr = server_p->get_service_registry();
  sr.register_service(0, new CoreService());
  
  L = lua_open();
  luaL_openlibs(L);
  
  lua_register(L, "listen_socket", listen_socket);
  
  // Push program arguments to LUA
  lua_createtable(L, argc, 0);
  int i;
  for (i=0; i < argc; i++) {
    lua_pushstring(L, argv[i]);
    lua_rawseti(L, -2, i + 1);
  }
  lua_setglobal(L, "arg");
  
  lua_pushstring(L, "0");
  lua_setglobal(L, "MAJOR_VERSION");
  lua_pushstring(L, "01-beta");
  lua_setglobal(L, "MINOR_VERSION");
    
  if(luaL_loadfile(L,"./scripts/sikozu.lua") > 0)
  {
     printf("Error failed to load %s",lua_tostring(L,-1));
     return 0;
  }
  
  int status = lua_pcall(L,0,0,0);
  
  if (status > 0) {
    std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1); // remove error message
  }

  // Run main loop
  cout << "Executing main loop." << endl;
  event_dispatch();
  
  lua_close(L);

  cout << "Exiting..." << endl;
  return 0;
}
