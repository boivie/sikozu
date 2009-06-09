/*
 *  transaction.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-06-05.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TRANSACTION_H_INCLUSION_GUARD
#define TRANSACTION_H_INCLUSION_GUARD

#include <memory>
#include "common.h"
#include "remoteservice.h"
#include "contact.h"
#include "request.h"
#include "thread.h"

namespace Sikozu {

class TransactionNotFoundException : public std::exception {};
class NotAvailableException : public std::exception {};

class Transaction {

};

class OutboundTransaction : public Transaction {
 public:
  friend class OutboundTransactionRegistry;
  static boost::shared_ptr<OutboundTransaction> create(ContactPtr contact_p, const RemoteService& destination_service);
  void set_timeout(int timeout_ms);
  bool has_timed_out() const;
  bool is_pending() const;
  void send_request(Command_t command, const std::vector<char>& payload);
  Request& get_response();
 private:
  OutboundTransaction(ContactPtr contact_p, Channel_t channel);
  Channel_t m_channel;
  ContactPtr m_contact_p;
  std::auto_ptr<Request> m_response_p;
  Thread& m_thread;
  bool m_has_timed_out;
  int m_timeout_ms;
};

class InboundTransaction : public Transaction {
 public:
  InboundTransaction(ContactPtr contact_p, uint32_t sid, std::auto_ptr<Request> request_p);
  
  void send_response(const std::vector<char>& payload);
  Request& get_request();  
  ContactPtr get_sender();

 private:  
  std::auto_ptr<Request> m_request_p;
  ContactPtr m_contact_p;
  uint32_t m_sid;
};


class OutboundTransactionRegistry {
 public:
  friend class OutboundTransaction;
  static boost::shared_ptr<OutboundTransaction> wake_up(ContactPtr contact_p, uint32_t sid, std::auto_ptr<Request> request_p);
  static void remove(uint32_t sid);
 
 protected:
  typedef std::map<uint32_t, boost::weak_ptr<Transaction> > TransactionMapping;
  static boost::mutex shared_mutex;
  static TransactionMapping s_transactions;
  static uint32_t s_last_used_sid;

};

typedef boost::shared_ptr<OutboundTransaction> OutboundTransactionPtr;

}

#endif