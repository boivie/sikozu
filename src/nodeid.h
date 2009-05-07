#ifndef NODEID_H_INCLUSION_GUARD
#define NODEID_H_INCLUSION_GUARD
/*
 *  nodeid.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <vector>
#include <ostream>

namespace Sikozu {
#define NID_SIZE_BITS 160
#define NID_SIZE_BYTES (NID_SIZE_BITS / 8)

#define SID_SIZE_BITS 144
#define SID_SIZE_BYTES (SID_SIZE_BITS / 8)

  using namespace std;
  class NodeId {
  public:
    NodeId();
    void get_bytes(vector<char> &bytes) { bytes = nid; };
    void set_bytes(vector<char> &bytes);
    char* get_ptr() { return &nid[0]; };
    size_t size() { return NID_SIZE_BYTES; };
    friend ostream& operator << (ostream& os, NodeId& N);
  private:
    vector<char> nid;
  };
}

#endif
