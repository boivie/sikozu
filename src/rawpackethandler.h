/*
 *  rawpackethandler.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RAW_PACKET_HANDLER_H_INCLUSION_GUARD
#define RAW_PACKET_HANDLER_H_INCLUSION_GUARD

#include <memory>
#include "request.h"

namespace Sikozu {

struct RawPacketHandler
{
  RawPacketHandler(std::auto_ptr<RawRequest> raw_p) : m_raw_p(raw_p) {}
  void run();
protected:
  std::auto_ptr<RawRequest> m_raw_p;
};

}

#endif
