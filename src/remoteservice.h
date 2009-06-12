/*
 *  remoteservice.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-07.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef REMOTE_SERVICE_H_INCLUSION_GUARD
#define REMOTE_SERVICE_H_INCLUSION_GUARD

#include "common.h"

namespace Sikozu {

class RemoteService {
  public:
    RemoteService() : m_channel(SIKOZU_CHANNEL_CORE) {}
    Channel_t get_channel() const { return m_channel; }
  private:
    Channel_t m_channel;
};
}

#endif
