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
#include <list>
#include <set>

#include "contact.h"

namespace Sikozu {

class BucketStore {
  public:
    BucketStore() : m_buckets(NID_SIZE_BITS) {}
    void insert(ContactPtr contact_p);
  protected:
    std::vector< std::list< ContactPtr > > m_buckets;
    std::map< NodeId, ContactPtr > m_all_contacts; 
};

}

#endif
