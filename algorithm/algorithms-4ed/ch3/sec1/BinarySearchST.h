#ifndef BINARYSEARCHST_H
#define BINARYSEARCHST_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "inc/compareTo.h"
#include <set>

template <typename _Key, typename _Tp> class BinarySearchST {
public:
  BinarySearchST(int cap): ks(new _Key[cap]), vs(new _Tp[cap]), n(0) {};
  ~BinarySearchST();

public:
  int size() const { return n; }
  bool isEmpty() const { return n == 0; }
  bool constains(_Key k) const { return ks[rank(k)] == k; };
  _Key minKey() const { return ks[0]; }
  _Key maxKey() const { return ks[n-1]; }
  _Key select(int k) const { return ks[k]; }
  _Key ceiling(_Key k) const { return ks[rank(k)]; }
  _Key floor(_Key k) const;
  
  _Tp get(_Key k) const;
  int rank(_Key k) const;
  void put(_Key k, _Tp v);
  void deleteKey(_Key k);
  std::set<_Key> keys() const { return keys(minKey(), maxKey()); }
  std::set<_Key> keys(_Key lo, _Key hi) const;

private:
  _Key* ks;
  _Tp* vs;
  int n;
};

template <typename _Key, typename _Tp>
inline BinarySearchST<_Key, _Tp>::~BinarySearchST() {
  delete [] ks;
  delete [] vs;
}

template <typename _Key, typename _Tp>
inline int BinarySearchST<_Key, _Tp>::rank(_Key k) const {
  auto lo = 0;
  auto hi = n - 1;
  
  while (lo <= hi) {
    auto mid = lo + (hi - lo) / 2;
    auto cmp = compareTo(k, ks[mid]);
    if (cmp < 0) {
      hi = mid - 1;
    } else if (cmp > 0) {
      lo = mid + 1;
    } else {
      return mid;
    }
  }
  return lo;
}

template <typename _Key, typename _Tp>
_Tp BinarySearchST<_Key, _Tp>::get(_Key k) const {
  if (isEmpty()) {
    throw std::runtime_error("empty symbol table");
  }
  
  auto i = rank(k);
  
  if (i < n && compareTo(ks[i], k) == 0) {
    return vs[i];
  } else {
    throw std::runtime_error("invalid key");
  }
}

template <typename _Key, typename _Tp>
void BinarySearchST<_Key, _Tp>::put(_Key k, _Tp v) {
  auto i = rank(k);

  if (i < n && compareTo(ks[i], k) == 0) {
    vs[i] = v;
    return;
  }
  
  for (int j = n; j > i; --j) {
    ks[j] = ks[j-1];
    vs[j] = vs[j-1];
  }
  ks[i] = k;
  vs[i] = v;
  ++n;
}

template <typename _Key, typename _Tp>
std::set<_Key> BinarySearchST<_Key, _Tp>::keys(_Key lo, _Key hi) const {
  std::set<_Key> ret;
  for (int i = rank(lo); i <= rank(hi); ++i) {
    ret.insert(ks[i]);
  }
  return ret;
}

#endif /* BINARYSEARCHST_H */
