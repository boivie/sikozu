/*
 *  request.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-11.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "request.h"
#include "session.h"
#include "common.h"

using namespace Sikozu;
using namespace std;

Request::Request(Command_t command, std::auto_ptr<std::vector<char> > payload_p)
 : m_payload_p(payload_p),
   m_command(command)
{

}

