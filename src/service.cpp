/*
 *  service.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "service.h"

namespace Sikozu 
{

void Service::handle_request(Client* client_p, Packet* packet_p)
{
  // Do nothing. Just clean up.
  delete client_p;
  delete packet_p;
}

}