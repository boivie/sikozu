/*
 *  simpledb.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SIMPLE_DB_H_INCLUSION_GUARD
#define SIMPLE_DB_H_INCLUSION_GUARD 

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <stdint.h>
#include <time.h>
#include "baseservice.h"
 
namespace Sikozu {
namespace SimpleDb {
  struct Value 
  {
    std::vector<char> data;
    std::string secret_hash;
    time_t expiry;
  };

  class SimpleDbService : public BaseService {
  public:
    SimpleDbService(const NodeId& mynid) : BaseService(mynid) {}
    const std::string& get_name() const;
    void on_transaction(std::auto_ptr<InboundTransaction> transaction_p);
  private:
    std::map<std::string, Value> m_values;
    void handle_put(InboundTransaction& transaction);
    void handle_get(InboundTransaction& transaction);
    void handle_delete(InboundTransaction& transaction);  
  };
}
}

#endif
