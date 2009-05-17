/*
 *  baseservice.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-17.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "baseservice.h"

using namespace std;
namespace Sikozu 
{

void BaseService::add_provider(ContactPtr contact_p)
{
  m_bucketstore.insert(contact_p);
}

void BaseService::find_nodes(NodeId& nodeid, list<ContactPtr> contacts)
{
  return m_bucketstore.get_closest(nodeid, contacts);
}

}