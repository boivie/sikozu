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

#include <google/protobuf/message.h>
#include "service.h"
#include "bucketstore.h"

namespace Sikozu {

class BaseService : public Service {
 public:
  BaseService(const NodeId& mynid) : m_bucketstore(mynid) {}
  virtual ~BaseService() {}
  virtual void find_nodes(NodeId& nodeid, std::list<ContactPtr>& contacts);
  virtual void add_provider(ContactPtr client_p);
  virtual Channel_t get_channel() const { return m_channel; }
  virtual void set_channel(Channel_t channel) { m_channel = channel; }
  
  virtual void send_reply(InboundTransaction& transaction, google::protobuf::Message& outmsg);
  virtual void parse_request(InboundTransaction& transaction, google::protobuf::Message& inmsg);
 protected:
  BucketStore m_bucketstore;
  Channel_t m_channel;
};

}
#endif
