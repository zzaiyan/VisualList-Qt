#ifndef LINKLIST_H
#define LINKLIST_H

#include "ListNode.h"
#include "baseList.h"

#define TT template <typename T>
#define List LinkList<T>
#define Node ListNode<T>

TT class LinkList : public BaseList<T> {
  int _size;
  Node *header, *trailer;

 protected:
  void _init();

 public:
  LinkList() { _init(); }
  LinkList(Node* p, int n);
  LinkList(const List& L);
  ~LinkList();
  // 重载赋值
  LinkList& operator=(const List& L);
  // 返回首末节点
  Node* first() const { return header->succ; }
  Node* last() const { return trailer->pred; }
  Node* begin() const { return header->succ; }
  Node* end() const { return trailer; }
  // 返回两端元素
  T& front() { return header->succ->data; }
  T& back() { return trailer->pred->data; }
  // 返回元素个数
  int size() { return _size; }
  // 返回p的n个真前驱中最后一个值为e的节点
  Node* find(const T& e, int n, Node* p);
  // 返回p的n个真后继中最后一个值为e的节点
  Node* find(const T& e, Node* p, int n);
  // 返回p的n个真前驱中最后一个不大于e的节点
  Node* search(const T& e, int n, Node* p);
  // 返回p的n个真后继中最后一个不大于e的节点
  Node* search(const T& e, Node* p, int n);
  // 前插
  Node* insertBefore(Node* p, const T& e);
  // 后插
  Node* insertAfter(Node* p, const T& e);
  // 首尾
  Node* push_front(const T& e);
  // 尾插
  Node* push_back(const T& e);
  // 首删
  T& pop_front() { return remove(0); }
  // 末删
  T& pop_back() { return remove(_size - 1); }
  // 循秩访问
  T& operator[](int r);
  // 复制节点(用于拷贝构造or赋值)
  void copyNodes(Node* p, int n);
  // 删除节点
  void remove(Node* p);
  // 清空内容
  int clear();
  // 唯一化
  int deduplicate();
  // 唯一化 - 有序
  int uniquify();
  // 排序 (始于p的n个连续元素)
  void selSort(Node* p, int n);
  void selSort();
  void insSort(Node* p, int n);
  void insSort();
  // 搜索最大值
  Node* selMax(Node* p, int n);
  Node* selMax();
};

TT List::LinkList(Node* p, int n) {
  _init();
  copyNodes(p, n);
}

TT List::LinkList(const List& L) {
  _init();
  copyNodes(L.header->succ, L._size);
}

TT List::~LinkList() {
  clear();
  delete header;
  delete trailer;
}

TT List& List::operator=(const List& L) {
  clear();
  copyNodes(L.header->succ, L._size);
  return *this;
}

TT void List::_init() {
  header = new Node;
  trailer = new Node;
  header->succ = trailer;
  trailer->pred = header;
  _size = 0;
}

TT T& List::operator[](int r) {
  Node* p = first();
  while (r-- > 0)
    p = p->succ;
  return p->data;
}

TT void List::copyNodes(Node* p, int n) {
  while (n--) {
    push_back(p->data);
    p = p->succ;
  }
}

TT Node* List::find(const T& e, int n, Node* p) {
  while (n-- > 0) {
    p = p->pred;
    if (e == p->data)
      return p;
  }
  return nullptr;
}

TT Node* List::find(const T& e, Node* p, int n) {
  for (int i = 0; i < n; i++)
    p = p->succ;
  return find(e, n, p);
}

TT Node* List::search(const T& e, int n, Node* p) {
  do {
    p = p->pred, n--;
  }                                   // R -> L
  while ((-1 < n) && (e < p->data));  // compare until Hit or Range-out
  return p;
}

TT Node* List::search(const T& e, Node* p, int n) {
  for (int i = 0; i < n; i++)
    p = p->succ;
  return search(e, n, p);
}

TT Node* List::insertBefore(Node* p, const T& e) {
  _size++;
  return p->insertAsPred(e);
}

TT Node* List::insertAfter(Node* p, const T& e) {
  _size++;
  return p->insertAsSucc(e);
}

TT Node* List::push_front(const T& e) {
  return insertAfter(header, e);
}

TT Node* List::push_back(const T& e) {
  return insertBefore(trailer, e);
}

TT void List::remove(Node* p) {
  _size--;
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p;
}

TT int List::clear() {
  int oldSize = _size;
  while (_size > 0)
    remove(header->succ);
  return oldSize;
}

TT int List::deduplicate() {
  if (_size < 2)
    return 0;
  int oldSize = _size, r = 1;
  auto p = first();
  while (p->succ != trailer) {
    p = p->succ;
    auto q = find(p->data, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}

TT int List::uniquify() {
  if (_size < 2)
    return 0;
  int oldSize = _size;
  Node *p = first(), *q;
  while (p->succ != trailer) {
    q = p->succ;
    if (q->data != p->data)
      p = q;  // if diff, continue
    else
      remove(q);  // if same, remove(q)
  }
  return oldSize - _size;
}

TT void List::selSort(Node* p, int n) {
  if (n < 2)  // skip the plain cases
    return;
  Node *head = p->pred, *tail = p;
  for (int i = 0; i < n; i++)
    tail = tail->succ;
  for (; n > 1; n--) {
    // Type 1:
    // delete and rebuild the Nodes
    //
    // insertBefore(tail, remove(selMax(head->succ, n)));

    // Type 2:
    // swap the two's value
    //
    // auto m = selMax(head->succ, n);
    // T temp = tail->pred->data;
    // tail->pred->data = m->data;
    // m->data = temp;

    // Type 3:  Optimal Sln
    // swap the Nodes via reconnect their lines
    //
    Node::posSwap(tail->pred, selMax(head->succ, n));

    tail = tail->pred;
  }
}

TT Node* List::selMax(Node* p, int n) {
  Node* m = p;
  while (--n) {
    p = p->succ;
    // once Greater or Equal, update m.
    if (!(p->data < m->data))
      m = p;
  }
  return m;
}

TT void List::selSort() {
  selSort(header->succ, _size);
}

TT Node* List::selMax() {
  return selMax(header->succ, _size);
}

TT void List::insSort(Node* p, int n) {
  if (n < 2)  // skip the plain cases
    return;
  for (int r = 0; r < n; r++) {
    // Just reconnect the lines to move the Node,
    // which is most Efficient.
    Node* pos = search(p->data, r, p);
    auto now = p;
    p = p->succ;
    now->pred->succ = now->succ, now->succ->pred = now->pred;  // short now
    now->pred = pos, now->succ = pos->succ;        // insert now as pos's succ
    now->pred->succ = now, now->succ->pred = now;  // too
  }
}

TT void List::insSort() {
  insSort(header->succ, _size);
}
#undef TT
#undef List
#undef Node
#endif  // LINKLIST_H
