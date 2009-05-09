/*
 *  bucketstore.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BUCKET_STORE_H_INCLUSION_GUARD
#define BUCKET_STORE_H_INCLUSION_GUARD

#include <netinet/in.h>
#include <vector>
#include <list>
#include <stdint.h>
#include "nodeid.h"
#include "client.h"

namespace Sikozu {

class BucketContact {
 public:
  Client& get_client() { return m_client; }
  uint32_t get_timestamp() { return m_timestamp; }
  void set_timestamp(uint32_t timestamp) { m_timestamp = timestamp; }
  
 protected:
  Client m_client;
  uint32_t m_timestamp;
};

class BucketStore {
  public:
    BucketStore() : m_buckets(NID_SIZE_BITS) {}
    void insert(Client* contact_p);
  protected:
    std::vector< std::list<BucketContact> > m_buckets;
};

}

#endif
