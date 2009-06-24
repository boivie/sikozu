/*
 *  finder.h
 *  sikozu
 *
 *  Created by Victor Boivie on 2009-05-25.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef FINDER_H_INCLUSION_GUARD
#define FINDER_H_INCLUSION_GUARD

#include <set>
#include <vector>
#include "nodeid.h"
#include "contact.h"
#include "transaction.h"

namespace Sikozu {

class NoMoreContacts : public std::exception {};

class FinderDistanceComparator {
 public:
  NodeId* m_nid;
  bool operator()(const ContactPtr& lhs, const ContactPtr& rhs) const {
    return (m_nid->closest(lhs->get_nodeid(), rhs->get_nodeid()) >= 0);
  } 
};

class FinderNodeIdComparator {
 public:
  bool operator()(const ContactPtr& lhs, const ContactPtr& rhs) const {
    return lhs->get_nodeid() < rhs->get_nodeid();
  } 
};

typedef enum {
  FINDER_PROGRESS_SENT_REQUEST,
  FINDER_PROGRESS_GOT_RESPONSE,
  FINDER_PROGRESS_GOT_TIMEOUT
} FinderProgress_t;

class Finder;

class FinderWorker : public OutboundTransactionCallback {
 public:
  FinderWorker(Finder* parent_p) : finder_p(parent_p) {}
  virtual void send_request() = 0;  
 protected:
  ContactPtr get_best_unvisited() const;
  void add_contact(ContactPtr contact_p) const;
  Finder* finder_p;
  OutboundTransactionPtr m_transaction_p;
  virtual void on_response(Request& response) = 0;
  void on_timeout();
};

class Finder
{
friend class FinderWorker;
 public:
  virtual ~Finder();
 protected:
  Finder(int k = 20, int alpha = 3);
  void do_find();
  
  typedef std::set<ContactPtr, FinderDistanceComparator> BestSoFar_t;
  typedef std::map<ContactPtr, FinderProgress_t, FinderNodeIdComparator> VisitedNodes_t;

  virtual FinderWorker& get_worker(int worker) = 0;
  ContactPtr get_best_unvisited();
  void add_contact(ContactPtr contact_p);
  bool is_finished() const;
  BestSoFar_t m_best_so_far;
  VisitedNodes_t m_visited_nodes;

  /** Number of results to return */
  int m_k;
  /** Number of parallel transactions to use */
  int m_alpha;
};

class NodeFinderWorker : public FinderWorker {
 public:
  NodeFinderWorker(Finder* finder_p) : FinderWorker(finder_p) {}
  virtual void send_request();
  virtual void on_response(Request& response);  
};

class NodeFinder : public Finder
{
friend class NodeFinderWorker;
public:
  NodeFinder(int k = 20, int alpha = 3);
  virtual void find(const NodeId& nid, const std::string& service, const std::vector<ContactPtr>& initial, std::vector<ContactPtr>& output);
protected:
  FinderWorker& get_worker(int worker) { return m_workers[worker]; }
  std::vector<NodeFinderWorker> m_workers;
  const std::string* m_service_p;
  const NodeId* m_nid_p;
};


}
#endif
