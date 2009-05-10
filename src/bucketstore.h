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

#include <vector>
#include "client.h"
#include "bucket.h"

namespace Sikozu {

class BucketStore {
  public:
    BucketStore() : m_buckets(NID_SIZE_BITS) {}
    void insert(Client* contact_p);
  protected:
    std::vector< Bucket > m_buckets;
};

}

#endif
