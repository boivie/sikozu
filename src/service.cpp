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

void Service::find_nodes(NodeId& nodeid, list<ContactPtr> contacts)
{
  return m_bucket_store.get_closest(nodeid, contacts);
}

}