/*
 *  service.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "service.h"

using namespace std;
namespace Sikozu 
{

void Service::handle_request(Client* client_p, PacketHeader* header_p, vector<char>* buffer_p)
{
  // Do nothing. Just clean up.
  delete client_p;
  delete header_p;
  delete buffer_p;
}

void Service::add_provider(Client* client_p)
{
  m_bucket_store.insert(client_p);
}

void Service::add_tracker(Client* client_p)
{

}

bool Service::handle_find_node_request(Client* client_p, PacketHeader* header_p)
{
  return true;
}

}