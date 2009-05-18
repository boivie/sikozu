/*
 *  baseservice.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-17.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef BASE_SERVICE_H_INCLUSION_GUARD
#define BASE_SERVICE_H_INCLUSION_GUARD

#include "service.h"
#include "bucketstore.h"

namespace Sikozu {

class BaseService : public Service {
 public:
  BaseService(NodeId& mynid) : m_bucketstore(mynid) {}
  virtual void find_nodes(NodeId& nodeid, std::list<ContactPtr>& contacts);
  virtual void add_provider(ContactPtr client_p);
  virtual Channel_t get_channel() const { return m_channel; }
  virtual void set_channel(Channel_t channel) { m_channel = channel; }
 protected:
  BucketStore m_bucketstore;
  Channel_t m_channel;
};

}
#endif
