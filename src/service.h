/*
 *  service.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SERVICE_H_INCLUSION_GUARD
#define SERVICE_H_INCLUSION_GUARD
 
#include "client.h"
#include "packetheader.h"
#include <vector>

namespace Sikozu {
  class Service {
   public:
    virtual const char* get_short_name() { return "default"; };
    virtual const char* get_long_name() { return "default"; };
    virtual void handle_request(Client* client_p, PacketHeader* header_p, std::vector<char>* buffer_p);
  };
}

#endif
