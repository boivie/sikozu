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

void Service::add_provider(ContactPtr contact_p)
{
  m_bucket_store.insert(contact_p);
}

void Service::add_tracker(ContactPtr contact_p)
{

}

bool Service::handle_find_node_request(auto_ptr<Request> request_p)
{
  return true;
}

}