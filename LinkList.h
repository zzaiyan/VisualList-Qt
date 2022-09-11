#ifndef LINKLIST_H
#define LINKLIST_H

#include "ListNode.h"

#define TT template <typename T>
#define List LinkList<T>
#define Node ListNode<T>

TT class LinkList {
  int _size;
  Node *header, *trailer;

  void _init();

 public:
  LinkList() { _init(); }
  ~LinkList();
  void clear();
  Node* insertBefore(Node* p, const T& e);
  Node* insertAfter(Node* p, const T& e);
};

TT List::~LinkList() {
  clear();
  delete header;
  delete trailer;
}

TT void List::_init() {
  header = new Node;
  _size = 0;
}

TT void List::clear() {
  _size = 0;
  for (auto p = header->succ; p != nullptr; p = p->succ)
    delete p;
}

TT Node* List::insertBefore(Node* p, const T& e) {
  _size++;
  return p->insertAsPred(e);
}

TT Node* List::insertAfter(Node* p, const T& e) {
  _size++;
  return p->insertAsSucc(e);
}

#undef TT
#undef List
#undef Node
#endif  // LINKLIST_H
