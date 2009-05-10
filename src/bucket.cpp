/*
 *  bucket.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "bucket.h"

using namespace Sikozu;
using namespace std;

bool Sikozu::operator<(const BucketContact& c1, const BucketContact& c2)
{
  const NodeId& n1 = c1.m_client.get_nodeid();
  const NodeId& n2 = c2.m_client.get_nodeid();  
  return n1 < n2;
}

void Bucket::insert(BucketContact& contact)
{
  m_contacts.insert(contact);
}
