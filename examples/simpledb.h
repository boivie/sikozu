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
    SimpleDbService(NodeId& mynid) : BaseService(mynid) {}
    const std::string& get_name() const;
    void handle_request(std::auto_ptr<Request> request_p);
  private:
    std::map<std::string, Value> m_values;
    void handle_put(Request& request);
    void handle_get(Request& request);
    void handle_delete(Request& request);  
  };
}
}

#endif
