/*
 *  packetheader.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "packetheader.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
 
#include <vector>
using namespace std;
using namespace google::protobuf::io;
namespace Sikozu {
  PacketHeader::PacketHeader()
  {
    m_sid.resize(SID_SIZE_BYTES);
  }
  
  size_t PacketHeader::parse(vector<char>* input_p)
  {
    if (input_p->size() < PACKET_HEADER_MINIMUM_SIZE) 
      return 0;
    ArrayInputStream instream(&(*input_p)[0], input_p->size());
    {
      CodedInputStream cis(&instream);
    
      if (!cis.ReadVarint32(&m_channel))
        return 0;
      
      if (!cis.ReadVarint32(&m_command))
        return 0;
    
      if (!cis.ReadRaw(&m_sid[0], m_sid.size()))
        return 0;

      if (!cis.ReadRaw(m_nid.get_ptr(), m_nid.size()))
        return 0;
    }
    m_size = instream.ByteCount();
    return m_size;
  }
  
  bool PacketHeader::serialize(google::protobuf::io::ZeroCopyOutputStream* output_p)
  {
    CodedOutputStream cos(output_p);
    if (!cos.WriteVarint32(m_channel))
      return false;
    if (!cos.WriteVarint32(m_command))
      return false;
    if (!cos.WriteRaw(&m_sid[0], m_sid.size()))
      return false;
    if (!cos.WriteRaw(m_nid.get_ptr(), m_nid.size()))
      return false;
    return true;
  }

  
  size_t PacketHeader::serialize(vector<char>* output_p)
  {
    ArrayOutputStream outstream(&(*output_p)[0], output_p->size());
    if (!serialize(&outstream))
      return 0;
    return outstream.ByteCount();
  }
}