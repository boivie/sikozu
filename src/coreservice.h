/*
 *  coreservice.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CORE_SERVICE_H_INCLUSION_GUARD
#define CORE_SERVICE_H_INCLUSION_GUARD 

#include <memory>
#include "baseservice.h"

namespace Sikozu {

  class CoreService : public BaseService {
  public:
    enum CommandIdentifier {
      PING_REQUEST,
      FIND_NODE_REQUEST,
      GET_SERVICES_REQUEST,
      ANNOUNCE_SERVICE_REQUEST,
      GET_CHANNEL_REQUEST,
      HELLO_REQUEST,
      LAST
    };  
    CoreService(const NodeId& mynid); 
    const std::string& get_name() const;
    void on_transaction(std::auto_ptr<InboundTransaction> transaction_p);
  protected:
    void handle_ping(InboundTransaction& transaction);
    void handle_get_services(InboundTransaction& transaction);
    void handle_find_node(InboundTransaction& transaction);
    void handle_announce_service(InboundTransaction& transaction);
    void handle_get_channel(InboundTransaction& transaction);
    void handle_hello(InboundTransaction& transaction);
  };
}

#endif
