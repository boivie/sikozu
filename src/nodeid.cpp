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
  int distance = NID_SIZE_BITS;
  
  for (int i = 0; i < m_nid.size(); i++)
  {
    uint8_t diff = m_nid[i] ^= other.m_nid[i];
    for (int j = 7; j >= 0; j--)
    {
      if (diff & (1 << j)) 
        return distance;
      distance--;
    }
  }
  assert(distance == 0);
  return distance;
}