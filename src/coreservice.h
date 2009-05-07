/*
 *  coreservice.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include "service.h"
 
namespace Sikozu {

  class CoreService : public Service {
  public:
    const char* get_name() { return "Core"; };
    void handle_request(Client* client_p, PacketHeader* header_p, std::vector<char>* buffer_p);
  };
}
