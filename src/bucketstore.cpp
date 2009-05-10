/*
 *  bucketstore.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "bucketstore.h"

#include "server.h"

using namespace Sikozu;
using namespace std;

void BucketStore::insert(Client* contact_p)
{
  NodeId& my_nid = Server::get_instance()->get_nid();
  int bucket_idx = contact_p->get_nodeid().get_log_distance(my_nid);
  assert((bucket_idx >= 0) && (bucket_idx < NID_SIZE_BITS));
  Bucket& bucket = m_buckets[bucket_idx];
  BucketContact contact;
  contact.get_client() = *contact_p;
  bucket.insert(contact);
}
