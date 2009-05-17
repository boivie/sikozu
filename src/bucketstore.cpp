/*
 *  bucketstore.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <assert.h>
#include "bucketstore.h"

#include "contact.h"

using namespace Sikozu;
using namespace std;

void BucketStore::insert(ContactPtr contact_p)
{
  int bucket_idx = contact_p->get_nodeid().get_log_distance(m_mynid);
  assert((bucket_idx >= 0) && (bucket_idx < NID_SIZE_BITS));
  list<ContactPtr>& bucket = m_buckets[bucket_idx];
  
  bucket.push_front(contact_p);
  m_all_contacts[contact_p->get_nodeid()] = contact_p;
}

void BucketStore::get_closest(NodeId& nodeid, list<ContactPtr>& contacts, size_t count)
{
  AllContacts_t::iterator iter_up = m_all_contacts.lower_bound(nodeid);
  AllContacts_t::reverse_iterator iter_down(iter_up);
  
  while (contacts.size() < count)
  {
    if ((iter_up == m_all_contacts.end()) && (iter_down == m_all_contacts.rend()))
    {
      // No more contacts anywhere.
      return;
    }
    else if ((iter_up != m_all_contacts.end()) && (iter_down == m_all_contacts.rend()))
    {
      // Can only add iter_up.
      contacts.push_back(iter_up->second);
      iter_up++;
    }
    else if ((iter_up == m_all_contacts.end()) && (iter_down != m_all_contacts.rend()))
    {
      // Can only add iter_up.
      contacts.push_back(iter_down->second);
      iter_down++;
    }
    else
    {
      if (nodeid.closest(iter_up->first, iter_down->first) < 0)
      {
        contacts.push_back(iter_up->second);
        iter_up++;
      }
      else
      { 
        contacts.push_back(iter_down->second);
        iter_down--;
      }
    }
  }
}
