#ifndef SEPARATECHAININGHASHST_H
#define SEPARATECHAININGHASHST_H

#include "inc/SequencialSearchST.h"
#include <cstddef>
#include <unordered_map>
#include <functional>
#include <vector>

template <typename _Key, typename _Tp> class SeparateChainingHashST {
public:
  SeparateChainingHashST(): SeparateChainingHashST(997) {}
  SeparateChainingHashST(int M);
  virtual ~SeparateChainingHashST() { delete [] st; }
public:
  _Tp get(_Key k) const { return st[hash(k)].get(k); }
  void put(_Key k, _Tp v) { st[hash(k)].put(k, v); }
  std::vector<_Key> keys() const;
private:
  size_t hash(_Key k) const { return std::hash<_Key>{}(k) % m; };

private:
  int n;
  int m;
  SequentialSearchST<_Key, _Tp> *st;
};

template <typename _Key, typename _Tp>
inline SeparateChainingHashST<_Key, _Tp>::SeparateChainingHashST(int M)
    : m(M), st(new SequentialSearchST<_Key, _Tp>[m]) {
  for (int i = 0; i < m; ++i) {
    st[i] = SequentialSearchST<_Key, _Tp>();
  }
}

/* template <typename _Key, typename _Tp> */
/* inline std::vector<_Key> SeparateChainingHashST<_Key, _Tp>::keys() const { */
/*   std::vector<_Key> ret; */
/*   for (int i = 0; i < m; ++i) { */
/*     auto temp = st->keys(); */
/*     if (st[i].size()){ */
/*       ret.insert(ret.end(), temp.begin(), temp.end()); */
/*     } */
/*   } */
/*   return ret; */
/* } */

#endif /* SEPARATECHAININGHASHST_H */
