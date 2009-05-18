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

Request::Request(PacketHeader& ph, ContactPtr contact_p, auto_ptr<vector<char> > payload_p)
 : m_sender_p(contact_p), 
   m_session_p(Session::create(contact_p, SIKOZU_CHANNEL_REPLY, ph.get_sid())),
   m_payload_p(payload_p),
   m_command(ph.get_command())
{

}

