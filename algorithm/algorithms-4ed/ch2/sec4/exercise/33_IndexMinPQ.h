#ifndef INDEXMINPQ_H
#define INDEXMINPQ_H

#include <cstddef>
#include <vector>

template <typename _Tp> class IndexMinPQ {
public:
  IndexMinPQ(int maxN);
  ~IndexMinPQ();

public:
  void insert(int k, _Tp key);
  int rmMin();
  bool empty() const { return n == 0; }
  int size() const { return n; }
  bool contains(int k) const { return qp[k] != -1; }
  _Tp min() const { return keys[pq[1]]; }

private:
  bool less(int i, int j);
  void swap(int i, int j);
  void swim(int i);
  void sink(int i);

private:
  int *pq;   // binary heap using 1-based indexing
  int *qp;   // inverse: qp[pq[i]] = pq[qp[i]] = i
  _Tp *keys; // items with properties
  int n;
};

template <typename _Tp>
IndexMinPQ<_Tp>::IndexMinPQ(int NMAX)
    : pq(new int[NMAX + 1]), qp(new int[NMAX + 1]), keys(new _Tp[NMAX + 1]),
      n(0) {
  for (int i = 0; i <= NMAX; ++i) {
    qp[i] = -1;
  }
}

template <typename _Tp> inline IndexMinPQ<_Tp>::~IndexMinPQ<_Tp>() {
  delete [] pq;
  delete [] qp;
  delete [] keys;
}

template <typename _Tp> void IndexMinPQ<_Tp>::swap(int i, int j) {
  auto temp = pq[i];
  pq[i] = pq[j];
  pq[j] = temp;

  qp[pq[i]] = i;
  qp[pq[j]] = j;
  
  /* temp = qp[i]; */
  /* qp[i] = qp[j]; */
  /* qp[j] = temp; */
}

template <typename _Tp> bool IndexMinPQ<_Tp>::less(int i, int j) {
  return keys[pq[i]] < keys[pq[j]];
}

template <typename _Tp> void IndexMinPQ<_Tp>::swim(int k) {
  while (k > 1 && less(k, k/2)) {
    swap(k, k/2);
    k /= 2;
  }
}

template <typename _Tp> void IndexMinPQ<_Tp>::sink(int k) {
  while (2*k <= n) {
    int j = 2*k;
    if (j < n && less(j+1, j)) {
      ++j;
    }
    if (!less(j, k)) {
      break;
    }
    swap(k, j);
    k = j;
  }
}

template <typename _Tp> void IndexMinPQ<_Tp>::insert(int i, _Tp key) {
  pq[++n] = i;
  qp[i] = n;
  keys[i] = key;
  swim(n);
}

template <typename _Tp> int IndexMinPQ<_Tp>::rmMin() {
  int min= pq[1];
  swap(1, n--);
  sink(1);
  pq[n+1] = -1;
  qp[min] = -1;
  return min;
}

#endif /* INDEXMINPQ_H */
