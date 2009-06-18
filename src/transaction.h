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
#include <set>
#include "common.h"
#include "remoteservice.h"
#include "contact.h"
#include "request.h"

namespace Sikozu {

// Has to forward-declare this since we need to include transaction.h in task.h
class Task;
class TransactionNotFoundException : public std::exception {};
class NotAvailableException : public std::exception {};

class Transaction {

};

class OutboundTransaction : public Transaction {
 public:
  friend class ActiveOutboundTransactions;
  friend class TransactionTimeComparator;
  ~OutboundTransaction();
  static boost::shared_ptr<OutboundTransaction> create(ContactPtr contact_p, const RemoteService& destination_service);
  void set_timeout(const int timeout_ms);
  bool has_timed_out() const;
  bool is_pending() const;
  void send_request(const Command_t command, const std::vector<char>& payload);
  Request& get_response();
  boost::shared_ptr<Task> get_task() { return m_task_p; }
  ContactPtr get_contact() { return m_contact_p; }
 private:
  uint32_t get_sid() const { return m_sid; } 
  void timeout();
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
  InboundTransaction(ContactPtr contact_p, const uint32_t sid, std::auto_ptr<Request> request_p);
  
  void send_response(const std::vector<char>& payload);
  Request& get_request();  
  ContactPtr get_sender();

 private:  
  std::auto_ptr<Request> m_request_p;
  ContactPtr m_contact_p;
  uint32_t m_sid;
};

class TransactionReply {
 public:
  TransactionReply(const uint32_t sid, ContactPtr contact_p, std::auto_ptr<Request> request_p) : m_sid(sid), m_contact_p(contact_p), m_request_p(request_p) {}
  ContactPtr get_contact() { return m_contact_p; }
  std::auto_ptr<Request> get_request() { return m_request_p; }
  virtual bool is_transaction_reply() const { return true; }
  uint32_t get_sid() const { return m_sid; }
 private:
  uint32_t m_sid;
  ContactPtr m_contact_p;
  std::auto_ptr<Request> m_request_p;
};

struct TimeoutTransactionInfo {
  TimeoutTransactionInfo(boost::system_time& abs_timeout, boost::shared_ptr<OutboundTransaction> transaction_p)
    : m_abs_timeout(abs_timeout), m_transaction_p(transaction_p) {}
  boost::system_time m_abs_timeout;
  boost::weak_ptr<OutboundTransaction> m_transaction_p;
};

  class TransactionTimeComparator {
  public:
    bool operator()(const TimeoutTransactionInfo& lhs, const TimeoutTransactionInfo& rhs) const {
      return (lhs.m_abs_timeout < rhs.m_abs_timeout);
    } 
  };  

class ActiveOutboundTransactions {
  friend class OutboundTransaction;
 
 // Object Methods
 public:
  void wake_up(std::auto_ptr<TransactionReply> reply_p);
  bool timeout_transactions();
  void get_next_timeout(boost::system_time& timeout);
  void add_timeout(boost::shared_ptr<OutboundTransaction> transaction_p, boost::system_time& abs_timeout);
  void cleanup_orphan_timeouts();
  
  typedef std::multiset<TimeoutTransactionInfo, TransactionTimeComparator> Timeout_Transactions_t;
  Timeout_Transactions_t m_timeout_transactions;
  
 // Static Methods
 public: 
  static boost::shared_ptr<Task> get_task(uint32_t sid);

 protected:
  static void add(boost::shared_ptr<OutboundTransaction> transaction_p);  
  static uint32_t get_new_sid();
  static boost::shared_ptr<OutboundTransaction> find(uint32_t sid);
  static void remove(uint32_t sid);

  typedef std::map<uint32_t, boost::weak_ptr<OutboundTransaction> > TransactionMapping;
  static boost::mutex s_mutex;
  static TransactionMapping s_transactions;
  static uint32_t s_last_used_sid;
};


typedef boost::shared_ptr<OutboundTransaction> OutboundTransactionPtr;

}

#endif
