#ifndef SEQUENCIALSEARCHST_H
#define SEQUENCIALSEARCHST_H

#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>

template <typename _Key, typename _Tp> struct Node {
  Node() = default;
  Node(_Key k, _Tp v, Node nx) : key(k), val(v), next(nx) {}
  _Key key;
  _Tp val;
  Node *next;
};

template <typename _Key, typename _Tp> class SequentialSearchST {
  friend Node<_Key, _Tp>;

public:
  SequentialSearchST() : head(new Node<_Key, _Tp>()), n(0) {}

public:
  bool contains(_Key key) const;
  bool isEmpty() const { return size() == 0; };

  _Key max() const;
  _Key min() const;

  _Key floor() const;
  _Key ceiling() const;

  int rank(_Key key) const;
  _Key select(int k) const;

  int size() const { return n; };
  int size(_Key lo, _Key hi) const;

  std::set<_Key> keys(_Key lo, _Key hi) const;
  std::set<_Key> keys() const { return keys(min(), max()); }

  void put(_Key key, _Tp val);
  const _Tp &get(_Key key) const;
  _Tp &get(_Key key);

private:
private:
  Node<_Key, _Tp> *head;
  int n;
};



#endif /* SEQUENCIALSEARCHST_H */
