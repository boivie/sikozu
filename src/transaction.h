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
#include "task.h"

namespace Sikozu {

class TransactionNotFoundException : public std::exception {};
class NotAvailableException : public std::exception {};

class Transaction {

};

class OutboundTransaction : public Transaction {
 public:
  ~OutboundTransaction();
  friend class OutboundTransactionRegistry;
  static boost::shared_ptr<OutboundTransaction> create(ContactPtr contact_p, const RemoteService& destination_service);
  void set_timeout(int timeout_ms);
  bool has_timed_out() const;
  bool is_pending() const;
  void send_request(Command_t command, const std::vector<char>& payload);
  Request& get_response();
  boost::shared_ptr<Task> get_task() { return m_task_p; }
  ContactPtr get_contact() { return m_contact_p; }
 private:
  uint32_t get_sid() const { return m_sid; } 
  OutboundTransaction(ContactPtr contact_p, const RemoteService& destination_service, uint32_t sid);
  void set_response(std::auto_ptr<Request> response_p) { m_response_p = response_p; }
  uint32_t m_sid;
  RemoteService m_service;
  ContactPtr m_contact_p;
  std::auto_ptr<Request> m_response_p;
  boost::shared_ptr<Task> m_task_p;
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
  static void redirect_to_task(ContactPtr contact_p, uint32_t sid, std::auto_ptr<Request> request_p);
  static void wake_up(ContactPtr contact_p, uint32_t sid, std::auto_ptr<Request> request_p);
  static void remove(uint32_t sid);
 
 protected:
  static void add(boost::shared_ptr<OutboundTransaction> transaction_p);
  static uint32_t get_sid();
  typedef std::map<uint32_t, boost::weak_ptr<OutboundTransaction> > TransactionMapping;
  static boost::mutex s_mutex;
  static TransactionMapping s_transactions;
  static uint32_t s_last_used_sid;

};

class TransactionReply {
 public:
  TransactionReply(uint32_t sid, ContactPtr contact_p, std::auto_ptr<Request> request_p) : m_sid(sid), m_contact_p(contact_p), m_request_p(request_p) {}
  ContactPtr get_contact() { return m_contact_p; }
  std::auto_ptr<Request> get_request() { return m_request_p; }
  virtual bool is_transaction_reply() const { return true; }
 private:
  uint32_t m_sid;
  ContactPtr m_contact_p;
  std::auto_ptr<Request> m_request_p;
};

typedef boost::shared_ptr<OutboundTransaction> OutboundTransactionPtr;

}

#endif