#ifndef LISTNODE_H
#define LISTNODE_H

#define TT template <typename T>
#define Node ListNode<T>

#include <algorithm>

TT struct ListNode {
  T data;
  Node *pred, *succ;

  ListNode() : data(std::move(T{})), pred(nullptr), succ(nullptr) {}
  ListNode(const T& e, Node* p = nullptr, Node* s = nullptr)
      : data(e), pred(p), succ(s) {}
  Node* insertAsPred(const T& e);
  Node* insertAsSucc(const T& e);
  static void posSwap(Node* p1, Node* p2);
};

TT Node* Node::insertAsPred(const T& e) {
  Node* x = new Node(e, pred, this);
  pred->succ = x, pred = x;
  return x;
}

TT Node* Node::insertAsSucc(const T& e) {
  Node* x = new Node(e, this, succ);
  succ->pred = x, succ = x;
  return x;
}

TT void Node::posSwap(Node* p1, Node* p2) {
  bool isNear = p1->succ == p2;
  Node* oldSucc = p1->succ;
  p1->pred->succ = p1->succ, p1->succ->pred = p1->pred;  // short p1
  p1->pred = p2, p1->succ = p2->succ;        // insert p1 as p2's succ
  p1->pred->succ = p1, p1->succ->pred = p1;  // too

  if (!isNear) {
    p2->pred->succ = p2->succ, p2->succ->pred = p2->pred;  // short p2
    p2->succ = oldSucc, p2->pred = oldSucc->pred;          // insert p2 to oldP1
    p2->pred->succ = p2, p2->succ->pred = p2;              // too
  }
}

#undef TT
#undef Node
#endif  // LISTNODE_H
