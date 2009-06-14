/*
 *  rawpackethandler.cpp
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-10.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "rawpackethandler.h"
#include "packetheader.h"
#include "transaction.h"
#include "server.h"

using namespace std;
using namespace Sikozu;

void RawPacketHandler::task_main()
{
  PacketHeader ph;

  ph.parse(&m_raw_p->buffer[0], m_raw_p->buffer_size);
  if (!ph.valid())
  {
    // Bad packet, drop.
    cerr << "Header validation failed, dropping packet." << endl;
    return;
  }

  ContactPtr contact_p = Contact::get(m_raw_p->from);

  size_t payload_size = m_raw_p->buffer_size - ph.size();
  auto_ptr<vector<char> > payload_p(new vector<char>(payload_size));
  if (payload_size > 0)
    memcpy(&(*payload_p)[0], &m_raw_p->buffer[ph.size()], payload_size);
    
  auto_ptr<Request> request_p(new Request(ph.get_command(), payload_p));

  // If this is a reply message, we must find a matching outbound transaction with this SID
  // to direct it to the correct task (running in its own thread).
  if (ph.get_channel() == SIKOZU_CHANNEL_REPLY)
  {
    try 
    {
      boost::shared_ptr<Task> task_p = ActiveOutboundTransactions::get_task(ph.get_sid());
      auto_ptr<TransactionReply> reply_p(new TransactionReply(ph.get_sid(), contact_p, request_p));
      task_p->post_event(reply_p);
    }
    catch (TaskNotFoundException& ex)
    {
      cerr << "Couldn't find task. Normal - don't bother." << endl;
    }
  }
  else
  {
    // This is a request - a start of a new inbound transaction.

    auto_ptr<InboundTransaction> transaction_p(new InboundTransaction(contact_p, ph.get_sid(), request_p));
    Server* server_p = Server::get_instance();
    ServiceRegistry& sr = server_p->get_service_registry();
    try 
    {
      Service& service = sr.get_service(ph.get_channel());
      try 
      {
        service.on_transaction(transaction_p);
      }
      catch (...)
      {
        cerr << "Exception occured during handle_request - dropping." << endl;
      }
    }
    catch (ServiceNotFoundException& ex)
    {
      cerr << "No service found." << endl;
    } 
  }
}