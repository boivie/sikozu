/*
 *  simpledb.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "simpledb.h"
#include "simpledb.pb.h"

using namespace Sikozu;
using namespace std;
using namespace Sikozu::SimpleDb;
using namespace google::protobuf::io;

enum {
  PUT_REQUEST, PUT_RESPONSE,
  GET_REQUEST, GET_RESPONSE,
  DELETE_REQUEST, DELETE_RESPONSE
};

const string& SimpleDbService::get_name() const {
  static const string name = "simpledb";
  return name;
}

#define DEFAULT_TTL 7*24*3600

void SimpleDbService::handle_put(std::auto_ptr<Request> request_p)
{
  Messages::PutRequest inmsg;
  
  parse_msg(*request_p, inmsg);

  Value value;
  size_t size = inmsg.value().size();
  value.data.resize(size);
  if (size > 0)
    memcpy(&value.data[0], inmsg.value().c_str(), size);
  
  value.secret_hash = inmsg.has_secret_hash() ? inmsg.secret_hash() : "";
  time_t ttl = inmsg.has_ttl() ? inmsg.ttl() : DEFAULT_TTL;
  if (ttl > DEFAULT_TTL) ttl = DEFAULT_TTL;
  value.expiry = time(NULL) + ttl;
    
  m_values[inmsg.key()] = value;
  
  Messages::PutResponse outmsg;
  outmsg.set_success(true);
  send_msg(*request_p, PUT_RESPONSE, outmsg);
}

void SimpleDbService::handle_get(std::auto_ptr<Request> request_p)
{
  Messages::GetRequest inmsg;
  
  parse_msg(*request_p, inmsg);

  map<std::string, Value>::iterator i = m_values.find(inmsg.key());
  
  Messages::GetResponse outmsg;
  outmsg.set_success(false);
  if (i != m_values.end())
  {
    Value& value = i->second;
    if (value.expiry >= time(NULL))
    {
      outmsg.set_success(true);
      if (value.data.size() > 0)
        outmsg.set_value(&value.data[0], value.data.size());
      else
        outmsg.set_value("");
    }
  }

  send_msg(*request_p, GET_RESPONSE, outmsg);
}

void SimpleDbService::handle_delete(std::auto_ptr<Request> request_p)
{
  
}

void SimpleDbService::handle_request(auto_ptr<Request> request_p)
{
  switch (request_p->get_command())
  {
  case PUT_REQUEST:
    handle_put(request_p);
    break;
  case GET_REQUEST:
    handle_get(request_p);
    break;
  case DELETE_REQUEST:
    handle_delete(request_p);
    break;
  default:
    cerr << "Got an unknown command: " << request_p->get_command() << endl; 
    break;
  }
} 
