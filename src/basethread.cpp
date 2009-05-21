/*
 *  basethread.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "basethread.h"

using namespace Sikozu;

struct wt_call {
  wt_call(BaseThread* wt) : m_wt(wt) {}
  void operator()() {  m_wt->thread_main(); }
  BaseThread* m_wt;
};


void BaseThread::start() 
{
  wt_call wt(this);
  m_me = boost::thread(wt);
}

void BaseThread::add_raw_request(RawRequest* request)
{
  m_queue.push(request);
}


