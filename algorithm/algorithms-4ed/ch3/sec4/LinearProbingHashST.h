#ifndef LINEARPROBINGHASHST_H
#define LINEARPROBINGHASHST_H

#include <cstddef>
#include <functional>
#include <stdexcept>

template <typename _Key, typename _Tp> class LinearProbingHashST {
public:
  LinearProbingHashST(size_t cap = 16);
  virtual ~LinearProbingHashST();

public:
  void put(_Key k, _Tp v);
  _Tp get(_Key k) const;
  void deleteKey(_Key k);
  bool constains(_Key k);

private:
  int hash(_Key k) const { return std::hash<_Key>{}(k) % m; }
  void resize(size_t cap);
  void free();
public:
  int searchCount = 0;

private:
  int n;
  int m;
  _Key **ks;
  _Tp *vs;
};

template <typename _Key, typename _Tp>
inline LinearProbingHashST<_Key, _Tp>::LinearProbingHashST(size_t cap)
    : m(cap), n(0), ks(new _Key *[m]), vs(new _Tp[m]) {
      for (int i = 0; i < m; i++) {
        ks[i] = nullptr;
      }
    }

template <typename _Key, typename _Tp>
inline LinearProbingHashST<_Key, _Tp>::~LinearProbingHashST() {
  free();
}

template <typename _Key, typename _Tp>
void LinearProbingHashST<_Key, _Tp>::put(_Key k, _Tp v) {
  if (n >= m / 2) {
    resize(2*m);
  }

  searchCount = 0;
  size_t i;
  for (i = hash(k); ks[i] != nullptr; i = (i + 1) % m) {
    ++searchCount;
    if (*ks[i] == k) {
      vs[i] = v;
      return;
    }
  }
  ks[i] = new _Key(k);
  vs[i] = v;
  ++n;
}

template <typename _Key, typename _Tp>
_Tp LinearProbingHashST<_Key, _Tp>::get(_Key k) const {
  size_t i;
  for (int i = hash(k); ks[i] != nullptr; i = (i + 1) % m) {
    if (*ks[i] == k) {
      return vs[k];
    }
  }
  throw std::runtime_error("invalid key");
}

// template <typename _Key, typename _Tp>
// void LinearProbingHashST<_Key, _Tp>::deleteKey(_Key k) {
//   
// }

template <typename _Key, typename _Tp>
void LinearProbingHashST<_Key, _Tp>::resize(size_t cap) {
  LinearProbingHashST<_Key, _Tp> temp(cap);
  for (int i = 0; i < m; ++i) {
    if (ks[i] != nullptr) {
      temp.put(*ks[i], vs[i]);
    }
  }

  free();
  
  ks = temp.ks;
  vs = temp.vs;
  temp.ks = nullptr;
  temp.vs = nullptr;
  m = temp.m;
}

template <typename _Key, typename _Tp>
void LinearProbingHashST<_Key, _Tp>::free() {
  for (int i = 0; i < m; ++i) {
    if (ks[i] != nullptr) {
      delete ks[i];
    }
  }
  delete[] ks;
  delete[] vs;
}

#endif /* LINEARPROBINGHASHST_H */
