/*
 *  bucketstore.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <assert.h>
#include <iostream>
#include "bucketstore.h"

#include "contact.h"

using namespace Sikozu;
using namespace std;
using namespace boost;

void BucketStore::insert(ContactPtr contact_p)
{
  int bucket_idx = contact_p->get_nodeid().get_log_distance(m_mynid) - 1;
  
  if (bucket_idx == -1)
  {
    // Can only happen if the distance was 0, i.e. my nid. Return quickly in that case.
    return;
  }
  
  {
    mutex::scoped_lock(m_mutex);
    assert((bucket_idx >= 0) && (bucket_idx < NID_SIZE_BITS));
    list<ContactPtr>& bucket = m_buckets[bucket_idx];
  
    bucket.push_front(contact_p);
    m_all_contacts.insert(contact_p);
  }
}

void BucketStore::get_closest(const NodeId& nodeid, list<ContactPtr>& contacts, size_t count)
{
  // A temporary object only used for searching in the list.
  ContactPtr needle_p = ContactRegistry::create_new(nodeid);
  mutex::scoped_lock(m_mutex);

  AllContacts_t::iterator iter_up = m_all_contacts.lower_bound(needle_p);
  AllContacts_t::reverse_iterator iter_down(iter_up);
  
//  cout << "Finding closest with " << m_all_contacts.size() << " contacts in bucket store." << endl;
  
  while (contacts.size() < count)
  {
    if ((iter_up == m_all_contacts.end()) && (iter_down == m_all_contacts.rend()))
    {
      // No more contacts anywhere.
      break;
    }
    else if ((iter_up != m_all_contacts.end()) && (iter_down == m_all_contacts.rend()))
    {
      // Can only add iter_up.
      contacts.push_back(*iter_up);
      iter_up++;
    }
    else if ((iter_up == m_all_contacts.end()) && (iter_down != m_all_contacts.rend()))
    {
      // Can only add iter_up.
      contacts.push_back(*iter_down);
      iter_down++;
    }
    else
    {
      if (nodeid.closest((*iter_up)->get_nodeid(), (*iter_down)->get_nodeid()) < 0)
      {
        contacts.push_back(*iter_up);
        iter_up++;
      }
      else
      { 
        contacts.push_back(*iter_down);
        iter_down++;
      }
    }
  }
//  cout << "Returned: " << contacts.size() << " contacts." << endl;
}
