#ifndef INDEXMINPQ_H
#define INDEXMINPQ_H

#include <cstddef>
#include <vector>
#include <functional>

template <typename _Tp> class IndexMinPQ {
public:
  IndexMinPQ(int maxN);
  ~IndexMinPQ();

public:
  bool empty() const { return n == 0; }
  int size() const { return n; }
  bool contains(int k) const { return index[k] != -1; }
  int minIndex() const { return pq[1]; }
  _Tp minKey() const { return keys[pq[1]]; }
  int keyOf(int k) const { return keys[k]; }
  void insert(int k, _Tp key);
  int deleteMin();
  void changeKey(int i, int key);
  void deleteKey(int i);

private:
  void swap(int i, int j);
  void bubbleUp(int i);
  void bubbleDown(int i);

private:
  std::less<_Tp> less;
  int *pq;   // binary heap using 1-based indexing
  int *index;   // inverse: qp[pq[i]] = pq[qp[i]] = i
  _Tp *keys; // items with properties
  int n;
};

template <typename _Tp> IndexMinPQ<_Tp>::IndexMinPQ(int NMAX)
    : pq(new int[NMAX + 1]), index(new int[NMAX + 1]), keys(new _Tp[NMAX + 1]),
      n(0) {
  for (int i = 0; i <= NMAX; ++i) {
    index[i] = -1;
  }
}

template <typename _Tp> inline IndexMinPQ<_Tp>::~IndexMinPQ<_Tp>() {
  delete [] pq;
  delete [] index;
  delete [] keys;
}

template <typename _Tp> void IndexMinPQ<_Tp>::insert(int k, _Tp key) {
  pq[++n] = k;
  index[k] = n;
  keys[k] = key;
  bubbleUp(n);
}

template <typename _Tp> int IndexMinPQ<_Tp>::deleteMin() {
  int minIndex = pq[1];
  swap(1, n--);
  bubbleDown(1);
  // pq[n+1] = -1;
  index[minIndex] = -1;
  return minIndex;
}

template <typename _Tp> void IndexMinPQ<_Tp>::changeKey(int k, int key) {
  keys[k] = key;
  bubbleUp(index[k]);
  bubbleDown(index[k]);
}

template <typename _Tp> void IndexMinPQ<_Tp>::deleteKey(int k) {
  auto ind = index[k];
  swap(ind, n--);
  bubbleUp(ind);
  bubbleDown(ind);
  index[k] = -1;
}

template <typename _Tp> void IndexMinPQ<_Tp>::bubbleUp(int k) {
  while (k > 1 && less(keys[pq[k]], keys[pq[k/2]])) {
    swap(k, k/2);
    k /= 2;
  }
}

template <typename _Tp> void IndexMinPQ<_Tp>::bubbleDown(int k) {
  int j;
  while (2*k <= n) {
    j = 2*k;
    if (j+1 <= n && less(keys[pq[j+1]], keys[pq[j]])) {
      ++j;
    }
    if (!less(keys[pq[j+1]], keys[pq[k]])) {
      break;
    }
    swap(k, j);
    k = j;
  }
}

template <typename _Tp> void IndexMinPQ<_Tp>::swap(int i, int j) {
  auto temp = pq[i];
  pq[i] = pq[j];
  pq[j] = temp;

  index[pq[i]] = i;
  index[pq[j]] = j;
}


#endif /* INDEXMINPQ_H */
