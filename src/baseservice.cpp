/*
 *  baseservice.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-17.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "baseservice.h"

using namespace google::protobuf::io;

using namespace std;
using namespace Sikozu;

void BaseService::add_provider(ContactPtr contact_p)
{
  m_bucketstore.insert(contact_p);
}

void BaseService::find_nodes(NodeId& nodeid, list<ContactPtr>& contacts)
{
  return m_bucketstore.get_closest(nodeid, contacts);
}

void BaseService::send_reply(InboundTransaction& transaction, google::protobuf::Message& outmsg)
{
  vector<char> buffer(8192);
  ArrayOutputStream outstream(&buffer[0], buffer.size());
  outmsg.SerializeToZeroCopyStream(&outstream);
  buffer.resize(outstream.ByteCount());
  transaction.send_response(buffer);
}

void BaseService::parse_request(InboundTransaction& transaction, google::protobuf::Message& inmsg)
{
  const vector<char>& payload = transaction.get_request().get_payload();
  ArrayInputStream instream(&payload[0], payload.size());

  if (!inmsg.ParseFromZeroCopyStream(&instream))
    throw "Failed to parse message";
}
