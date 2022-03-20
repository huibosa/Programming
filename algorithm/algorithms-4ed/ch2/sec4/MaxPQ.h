#ifndef MAXPQ_H
#define MAXPQ_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <type_traits>
#include <utility>

template <typename _Tp> class MaxPQ {
public:
  MaxPQ(size_t maxN) : pq(new _Tp[maxN + 1]()), n(0) {}
  ~MaxPQ() { delete [] pq; }
public:
  size_t size() const { return n; }
  bool empty() const { return n == 0; }
  void insert(_Tp item);
  _Tp rmMax();
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

template <typename _Tp> void MaxPQ<_Tp>::insert(_Tp item) {
  pq[++n] = item;
  swim(n);
}

template <typename _Tp> _Tp MaxPQ<_Tp>::rmMax() {
  auto max = pq[1];
  std::swap(pq[1], pq[n--]);
  sink(1);
  return max;
}

template <typename _Tp> void MaxPQ<_Tp>::swim(size_t k) {
  while (k > 1 && less(pq[k/2], pq[k])) {
    std::swap(pq[k], pq[k/2]);
    k /= 2;
  }
}

template <typename _Tp> void MaxPQ<_Tp>::sink(size_t k) {
  while (2*k <= n) {
    size_t j = 2*k;
    if (j+1 <= n && less(pq[j], pq[j+1])) {
      j++;
    }
    if (!less(pq[k], pq[j])) {
      break;
    }
    std::swap(pq[k], pq[j]);
    k = j;
  }
}

#endif /* MINPQ_H */
