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
#include "nodeid.h"
#include "common.h"
#include <google/protobuf/io/zero_copy_stream.h>

/*
 HeaderNr (1) (highest bit set means "more headers coming")
 Len(1) -- number of 32-bit words, including this one
 CRC16 (2)
 Channel (2)
 Command (2)
 Sid  # (4)
 total= min 4+4+4+20 = 12 = 3 words
*/

namespace Sikozu {

#define PACKET_HEADER_SIZE 12

  class PacketHeader {
   public:
    PacketHeader() {};
    size_t parse(char* ptr_p, size_t size);
    size_t serialize(char* ptr_p, size_t size);

    Channel_t get_channel() { return m_channel; };
    void set_channel(Channel_t channel) { m_channel = channel; }
    
    Command_t get_command() { return m_command; };
    void set_command(Command_t command) { m_command = command; }
    
    uint32_t get_sid() const { return m_sid; }
    void set_sid(uint32_t sid) { m_sid = sid; }
    size_t size() const { return m_size; }
    
    bool valid() const { return m_valid; }
    
   private:
    bool m_valid;
    Channel_t m_channel; 
    Command_t m_command;
    uint32_t m_sid;
    size_t m_size;
  };
}

#endif
