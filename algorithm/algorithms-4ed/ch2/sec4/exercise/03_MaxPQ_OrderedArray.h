#ifndef MAXPQ_ORDEREDARRAY_H
#define MAXPQ_ORDEREDARRAY_H

#include <cstddef>
#include <functional>
#include <iostream>

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

template <typename _Tp> void MaxPQ<_Tp>::insert(_Tp item) {
  size_t i = n - 1;
  while (i >= 0 && less(item, pq[i])) {
    pq[i+1] = pq[i];
    --i;
  }
  ++n;
  pq[i+1] = item;
}

template <typename _Tp> _Tp MaxPQ<_Tp>::rmMax() {
  auto max = pq[n-1];
  --n;
  return max;
}


#endif /* MAXPQ_ORDEREDARRAY_H */
