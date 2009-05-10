/*
 *  bucket.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef BUCKET_H_INCLUSION_GUARD
#define BUCKET_H_INCLUSION_GUARD

#include <netinet/in.h>
#include <set>
#include <stdint.h>
#include "client.h"
#include "nodeid.h"

namespace Sikozu {

class BucketContact {
 public:
  Client& get_client() { return m_client; }
  uint32_t get_timestamp() { return m_timestamp; }
  void set_timestamp(uint32_t timestamp) { m_timestamp = timestamp; }
  friend bool operator < (const BucketContact& c1, const BucketContact& c2);
 protected:
  Client m_client;
  uint32_t m_timestamp;
};

class Bucket {
 public:
  std::set<BucketContact>& get_contacts() { return m_contacts; }
  
  void insert(BucketContact& contact);
 protected:
  std::set<BucketContact> m_contacts;
};

}

#endif
