/*
 *  packet.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "packet.h"

#include "packetheader.h"
#include <google/protobuf/io/zero_copy_stream_impl.h>

using namespace google::protobuf::io;

namespace Sikozu 
{

Packet::Packet(vector<char>** buffer_pp) 
 : m_buffer_p(*buffer_pp), m_instream(&(**buffer_pp)[0], (*buffer_pp)->size())
{
  m_is_valid = m_header.parse(&m_instream);
  *buffer_pp = NULL;
}

Packet::~Packet()
{
  delete m_buffer_p;
}


}