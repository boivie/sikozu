/*
 *  packetheader.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-04.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include <iostream>
#include "packetheader.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
 
using namespace std;
using namespace google::protobuf::io;
using namespace Sikozu;
  
  size_t PacketHeader::parse(const char* ptr_p, size_t size)
  {
    m_valid = false;

    if (size < PACKET_HEADER_SIZE) 
      return 0;
          
    int headernr = (int)*ptr_p;
    if (headernr != 1) 
    {
      cout << "Invalid header nr given: " << headernr << endl;
      return 0;
    }
    
    m_size = (uint32_t)*(ptr_p + 1) * 4;
    if ((m_size < PACKET_HEADER_SIZE) || (m_size > size)) 
    {
      cout << "Invalid header size: " << m_size << endl;
      return 0;
    }

    uint16_t crc = *(uint16_t*)(ptr_p + 2);
    m_channel = (Channel_t)*(uint16_t*)(ptr_p + 4);
    m_command = (Command_t)*(uint16_t*)(ptr_p + 6);
    m_sid = *(uint32_t*)(ptr_p + 8);
    m_valid = true;
    return m_size;
  }

  size_t PacketHeader::serialize(char* ptr_p, size_t size)
  {
    if (size < PACKET_HEADER_SIZE)
      return 0;
    
    *ptr_p = 1;
    *(ptr_p + 1) = 3;
    *(uint16_t*)(ptr_p + 2) = 0xFFFF;
    *(uint16_t*)(ptr_p + 4) = m_channel;
    *(uint16_t*)(ptr_p + 6) = m_command;
    *(uint32_t*)(ptr_p + 8) = m_sid;
    return PACKET_HEADER_SIZE;
  }
