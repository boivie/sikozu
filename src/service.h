/*
 *  service.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SERVICE_H_INCLUSION_GUARD
#define SERVICE_H_INCLUSION_GUARD
 
#include "client.h"
#include "packetheader.h"
#include "bucketstore.h"
#include <vector>

namespace Sikozu {
  class Service {
   public:
    virtual ~Service() {};
    virtual const char* get_short_name() = 0;
    virtual const char* get_long_name() = 0;
    virtual void handle_request(Client* client_p, PacketHeader* header_p, std::vector<char>* buffer_p);
    virtual bool handle_find_node_request(Client* client_p, PacketHeader* header_p);
    virtual void add_provider(Client* client_p);
    virtual void add_tracker(Client* client_p);
   protected:
    BucketStore m_bucket_store;
  };
}

#endif
