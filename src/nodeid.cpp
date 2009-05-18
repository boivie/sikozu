/*
 *  nodeid.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <string.h>
#include <assert.h>
#include "nodeid.h"

using namespace Sikozu;
using namespace std;
    
NodeId::NodeId(const string& bytes)
 : m_nid(NID_SIZE_BYTES)
{
  if (bytes.size() == NID_SIZE_BYTES)
  {
    memcpy(&m_nid[0], bytes.c_str(), NID_SIZE_BYTES);
  }
  else
  {
    throw "Invalid size of NID";
  }
}
    
ostream& operator << (ostream& os, NodeId& N)
{
  os << "<NodeId: 'xxxxxxxx'>";
  return os;
}

const static uint8_t lookup[256] = {
  8, 
  7, 
  6, 6, 
  5, 5, 5, 5, 
  4, 4, 4, 4, 4, 4, 4, 4,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int NodeId::get_log_distance(NodeId& other) const
{
  int distance = NID_SIZE_BITS;
  
  for (size_t i = 0; i < m_nid.size(); i++)
  {
    uint8_t diff = m_nid[i] ^ other.m_nid[i];
    if (diff != 0)
      return distance - lookup[diff];
    distance -= 8;
  }
  assert(distance == 0);
  return distance;
}

int NodeId::closest(const NodeId& left, const NodeId& right) const
{
  for (size_t i = 0; i < m_nid.size(); i++)
  {
    uint8_t diff_l = m_nid[i] ^ left.m_nid[i];
    uint8_t diff_r = m_nid[i] ^ right.m_nid[i];
    if (diff_l < diff_r)
      return -1;
    else if (diff_r < diff_l)
      return 1;
  }
  return 0;
}
