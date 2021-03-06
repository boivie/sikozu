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
  class NodeId {
  public:
    NodeId();
    NodeId(const std::string& bytes);
    size_t size() const { return NID_SIZE_BYTES; }
    std::vector<uint8_t> get_bytes() const;
    int closest(const NodeId& left, const NodeId& right) const;
    int get_log_distance(const NodeId& other) const;
    friend std::ostream& operator << (std::ostream& os, NodeId& N);
    friend bool operator < (const NodeId& n2, const NodeId& n1) { return n2.m_nid < n1.m_nid; }
  private:
    uint8_t m_nid[NID_SIZE_BYTES];
  };
}

#endif
