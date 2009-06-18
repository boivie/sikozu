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
#include <boost/thread/mutex.hpp>

#include "contact.h"

namespace Sikozu {

class AllContactsComparator {
 public:
  bool operator()(const ContactPtr& lhs, const ContactPtr& rhs) const {
    return (lhs->get_nodeid() < rhs->get_nodeid());
  } 
};

class BucketStore {
  public:
    BucketStore(const NodeId& mynid) : m_mynid(mynid), m_buckets(NID_SIZE_BITS) {}
    void insert(ContactPtr contact_p);
    void get_closest(NodeId& nodeid, std::list<ContactPtr>& contacts, size_t count = 20);
  protected:
    boost::mutex m_mutex;
    const NodeId& m_mynid;
    std::vector< std::list< ContactPtr > > m_buckets;
    typedef std::set< ContactPtr, AllContactsComparator > AllContacts_t;
    AllContacts_t m_all_contacts; 
};

}

#endif
