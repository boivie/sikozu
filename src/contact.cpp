/*
 *  contact.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "contact.h"

using namespace Sikozu;
using namespace std;

ContactPtr Contact::get(struct sockaddr_in6& address)
{
  return ContactPtr(new Contact(address));
}