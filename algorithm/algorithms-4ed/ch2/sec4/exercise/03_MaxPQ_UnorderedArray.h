#ifndef MAXPQ_UNORDEREDARRAY_H
#define MAXPQ_UNORDEREDARRAY_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <type_traits>

template <typename _Tp> class MaxPQ {
public:
  MaxPQ(int maxN): pq(new _Tp[maxN]()), n(0) {}
  ~MaxPQ() { delete [] pq; }

public:
  void insert(_Tp item);
  _Tp rmMax();
  size_t size() { return n; }
  bool empty() { return n == 0; }
  _Tp* begin() { return pq; }
  _Tp* end() { return pq + n; }

private:
  std::less<_Tp> less;
  _Tp* pq;
  int n;
};

template <typename _Tp> inline void MaxPQ<_Tp>::insert(_Tp item) {
  pq[++n] = item;
}

template <typename _Tp> _Tp MaxPQ<_Tp>::rmMax() {
  size_t maxValIndex = 0;
  for (int i = 1; i < n; ++i) {
    if (less(pq[maxValIndex], pq[i])) {
      maxValIndex = i;
    }
  }
  
  auto max = pq[maxValIndex];
  std::swap(pq[maxValIndex], pq[n-1]);
  --n;

  return max;
}

#endif /* MAXPQ_UNORDEREDARRAY_H */
