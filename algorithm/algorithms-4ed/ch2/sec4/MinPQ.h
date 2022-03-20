#ifndef MINPQ_H
#define MINPQ_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <type_traits>
#include <utility>

template <typename _Tp> class MinPQ {
public:
  MinPQ(size_t maxN): pq(new _Tp[maxN+1]()), n(0) {}
  ~MinPQ() { delete [] pq; }
public:
  size_t size() const { return n; }
  bool empty() const { return n == 0; }
  void insert(_Tp item);
  _Tp rmMin();
  _Tp* begin() { return pq + 1; }
  _Tp* end() { return pq + n + 1; }
private:
  void swim(size_t i);
  void sink(size_t i);
private:
  std::less<_Tp> less;
  _Tp * pq;
  int n;
};

template <typename _Tp> void MinPQ<_Tp>::insert(_Tp item) {
  pq[++n] = item;
  swim(n);
}

template <typename _Tp> _Tp MinPQ<_Tp>::rmMin() {
  auto min = pq[1];
  std::swap(pq[1], pq[n--]);
  sink(1);
  return min;
}

template <typename _Tp> void MinPQ<_Tp>::swim(size_t k) {
  while (k > 1 && less(pq[k], pq[k/2])) {
    std::swap(pq[k], pq[k/2]);
    k /= 2;
  }
}

template <typename _Tp> void MinPQ<_Tp>::sink(size_t k) {
  while (2*k <= n) {
    size_t j = 2*k;
    if (j+1 <= n && less(pq[j+1], pq[j])) {
      j++;
    }
    if (!less(pq[j], pq[k])) {
      break;
    }
    std::swap(pq[k], pq[j]);
    k = j;
  }
}

#endif /* MINPQ_H */
