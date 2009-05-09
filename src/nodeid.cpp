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
using namespace std;
    
ostream& operator << (ostream& os, NodeId& N)
{
  os << "<NodeId: 'xxxxxxxx'>";
  return os;
}

int NodeId::get_log_distance(NodeId& other)
{
  vector<uint8_t> nid_copy = m_nid;
  vector<uint8_t>& other_nid = other.m_nid;
  for (int i = 0; i < nid_copy.size(); i++)
  {
    nid_copy[i] ^= other_nid[i];
  }
  return 1;
}