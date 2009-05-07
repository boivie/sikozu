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
 
#include <vector>
using namespace std;
using namespace google::protobuf::io;
namespace Sikozu {
  PacketHeader::PacketHeader()
  {
    m_sid.resize(SID_SIZE_BYTES);
  }
  
  bool PacketHeader::parse(ZeroCopyInputStream* input)
  {
    {
      CodedInputStream cis(input);
    
      if (!cis.ReadVarint32(&m_channel))
        return false;
      
      if (!cis.ReadVarint32(&m_command))
        return false;
    
      if (!cis.ReadRaw(&m_sid[0], m_sid.size()))
        return false;

      if (!cis.ReadRaw(m_nid.get_ptr(), m_nid.size()))
        return false;
    }
    m_size = input->ByteCount();
    return true;
  }
  
  bool PacketHeader::serialize(ZeroCopyOutputStream* output)
  {
    CodedOutputStream cos(output);
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
}