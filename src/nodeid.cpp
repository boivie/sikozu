/*
 *  nodeid.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "nodeid.h"

using namespace Sikozu;

NodeId::NodeId()
{
  nid.reserve(NID_SIZE_BYTES);
}

void NodeId::set_bytes(vector<char> &bytes)
{
  if (bytes.size() == NID_SIZE_BYTES)
    nid = bytes;
}
    
ostream& operator << (ostream& os, NodeId& N)
{
  os << "<NodeId: 'xxxxxxxx'>";
  return os;
}