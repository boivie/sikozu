/*
 *  nodeid.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef NODEID_H_INCLUSION_GUARD
#define NODEID_H_INCLUSION_GUARD
  
#include <vector>
#include <ostream>

namespace Sikozu {
#define NID_SIZE_BITS 160
#define NID_SIZE_BYTES (NID_SIZE_BITS / 8)

#define SID_SIZE_BITS 144
#define SID_SIZE_BYTES (SID_SIZE_BITS / 8)

  class NodeId {
  public:
    NodeId() : m_nid(NID_SIZE_BYTES) {}
    std::vector<uint8_t>& get_nid() { return m_nid; }
    size_t size() { return NID_SIZE_BYTES; }
    int get_log_distance(NodeId& other);
    friend std::ostream& operator << (std::ostream& os, NodeId& N);
  private:
    std::vector<uint8_t> m_nid;
  };
}

#endif
