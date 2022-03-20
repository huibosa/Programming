#ifndef LIST_H
#define LIST_H

// a singly linked list

#include <cstddef>
#include <stdexcept>

template <typename _Tp> struct Node {
  Node(_Tp i): data(i), next(nullptr) {}
  _Tp data;
  Node* next;
};

template <typename _Tp> class List {
public:
  List(): head(nullptr), tail(nullptr), n(0) {}
  ~List();
public:
  size_t size() const { return n; }
  bool empty() const { return n == 0; }
  _Tp front() const { return head->data; }
  _Tp back() const { return tail->data; }
  void push_back(_Tp item);
  void push_front(_Tp item);
  void pop_back();
  void pop_front();
private:
  Node<_Tp>* make_node(_Tp item);
private:
  Node<_Tp>* head;
  Node<_Tp>* tail;
  size_t n;
};

template <typename _Tp> List<_Tp>::~List<_Tp>() {
  while (head != nullptr) {
    auto temp = head->next;
    delete head;
    head = temp;
  }
}

template <typename _Tp> Node<_Tp>* List<_Tp>::make_node(_Tp item) {
  auto pnew = new Node<_Tp>(item);
  if (pnew == nullptr) {
    throw std::runtime_error("allocation overflow\n");
  }
  pnew->next = nullptr;

  return pnew;
}

template <typename _Tp> void List<_Tp>::push_back(_Tp item) {
  auto pnew = make_node(item);
  if (empty()) {
    head = tail = pnew;
  } else {
    tail->next = pnew;
    tail = pnew;
  }
  ++n;
}

template <typename _Tp> void List<_Tp>::push_front(_Tp item) {
  auto pnew = make_node(item);
  if (empty()) {
    head = tail = pnew;
  } else {
    pnew->next = head;
    head = pnew;
  }
  ++n;
}

template <typename _Tp> void List<_Tp>::pop_front() {
  if (empty()) {
    throw std::runtime_error("pop underflow\n");
  }
  --n;
  auto temp = head;
  head = head->next;
  delete temp;
}

template <typename _Tp> void List<_Tp>::pop_back() {
  if (empty()) {
    throw std::runtime_error("pop underflow\n");
  }
  --n;
  auto cur = head;
  while (cur->next != tail) {
    cur = cur->next;
  }
  cur->next = nullptr;
  delete tail;
  tail = cur;
}


#endif /* LIST_H */
