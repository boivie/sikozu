/*
 *  packet.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#ifndef PACKET_H_INCLUSION_GUARD
#define PACKET_H_INCLUSION_GUARD

#include "packetheader.h"
#include <google/protobuf/io/zero_copy_stream_impl.h>

namespace Sikozu {

class Packet {
 public:
  Packet(vector<char>** buffer_pp);
  ~Packet();
  std::vector<char>* get_buffer() { return m_buffer_p; };
  google::protobuf::io::ZeroCopyInputStream* get_instream() { return &m_instream; };
  PacketHeader* get_header() { return &m_header; };
  bool is_valid() { return m_is_valid; };
  
 private:
  google::protobuf::io::ArrayInputStream m_instream;
  std::vector<char>* m_buffer_p;
  PacketHeader m_header;
  bool m_is_valid;
};
}

#endif
