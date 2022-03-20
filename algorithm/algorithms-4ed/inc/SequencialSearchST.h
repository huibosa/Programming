#ifndef SEQUENCIALSEARCHST_H
#define SEQUENCIALSEARCHST_H

#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename _Key, typename _Tp> class Node;

template <typename _Key, typename _Tp> class SequentialSearchST {
  friend Node<_Key, _Tp>;

public:
  SequentialSearchST() : head(nullptr) {}
  ~SequentialSearchST();

public:
  std::vector<_Key> keys() const;
  bool contains(_Key) const;
  void put(_Key key, _Tp val);
  _Tp get(_Key key);

public:
  int searchCount;
private:
  Node<_Key, _Tp> *head;
};

template <typename _Key, typename _Tp> struct Node {
  Node() = default;
  Node(_Key k, _Tp v, Node* nx) : key(k), val(v), next(nx) {}
  _Key key;
  _Tp val;
  Node *next;
};

template <typename _Key, typename _Tp>
SequentialSearchST<_Key, _Tp>::~SequentialSearchST<_Key, _Tp>() {
  for (auto p = head; p != nullptr; p = p->next) {
    delete p;
  }
  head = nullptr;
}

template <typename _Key, typename _Tp>
std::vector<_Key> SequentialSearchST<_Key, _Tp>::keys() const {
  std::vector<_Key> ret;
  for (auto p = head; p != nullptr; p = p->next) {
    ret.push_back(p->key);
  }
  return ret;
}

template <typename _Key, typename _Tp>
bool SequentialSearchST<_Key, _Tp>::contains(_Key key) const {
  for (auto p = head; p != nullptr; p = p->next) {
    if (p->key == key) {
      return true;
    }
  }
  return false;
}


template <typename _Key, typename _Tp>
void SequentialSearchST<_Key, _Tp>::put(_Key key, _Tp val) {
  searchCount = 0;
  for (auto p = head; p != nullptr; p = p->next) {
    ++searchCount;
    if (p->key == key) {  // search hit: update val
      p->val = val;
      return;
    }
  }
  std::cout << searchCount << "\n";
  // search miss, add new node
  head = new Node<_Key, _Tp>(key, val, head);
}

template <typename _Key, typename _Tp>
_Tp SequentialSearchST<_Key, _Tp>::get(_Key key) {
  for (auto p = head; p != nullptr; p = p->next) {
    if (p->key == key) {
      return p->val;
    }
  }
  throw std::runtime_error("invalid key");
}

#endif /* SEQUENCIALSEARCHST_H */
