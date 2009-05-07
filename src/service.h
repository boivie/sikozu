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
#include "packet.h"

namespace Sikozu {
  class Service {
   public:
    virtual void handle_request(Client* client_p, Packet* packet_p);
  };
}

#endif
