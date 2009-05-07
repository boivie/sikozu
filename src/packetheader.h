/*
 *  headerparser.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef PACKETHEADER_H_INCLUSION_GUARD
#define PACKETHEADER_H_INCLUSION_GUARD

#include <vector>
#include <stdint.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include "nodeid.h"

namespace Sikozu {
  class PacketHeader {
   public:
    PacketHeader();
    bool parse(google::protobuf::io::ZeroCopyInputStream* input);
    bool serialize(google::protobuf::io::ZeroCopyOutputStream* output);

    int get_channel() { return m_channel; };
    void set_channel(int channel) { m_channel = channel; };
    
    int get_command() { return m_command; };
    void set_command(int command) { m_command = command; };
    
    void get_nid(NodeId &nid) { nid = m_nid; };
    void set_nid(NodeId &nid) { m_nid = nid; };
    void get_sid(std::vector<char> &sid) { sid = m_sid; };
    void set_sid(std::vector<char> &sid) { m_sid = sid; };
    
    size_t get_size() { return m_size; };
   private:
    uint32_t m_channel; 
    uint32_t m_command;
    NodeId m_nid;
    std::vector<char> m_sid;
    size_t m_size;
  };
}

#endif
