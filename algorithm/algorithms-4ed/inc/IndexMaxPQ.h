#ifndef INDEXMAXPQ_H
#define INDEXMAXPQ_H

#include <functional>

template <typename _Tp> class IndexMaxPQ {
public:
  IndexMaxPQ(int NMAX);
  ~IndexMaxPQ();
public:
  bool empty() const { return n == 0; }
  int size() const { return n; }
  bool contains(int k) const { return index[k] != -1; }
  int maxIndex() const { return pq[1]; }
  int maxKey() const { return keys[pq[1]]; }
  _Tp keyOf(int k) const { return keys[k]; }
  void insert(int k, _Tp key);
  int deleteMax();
  void changeKey(int k, _Tp key);
  void deleteKey(int k);
  
private:
  void bubbleUp(int k);
  void bubbleDown(int k);
  void swap(int i, int j);

private:
  std::less<_Tp> less;
  int n;
  int *pq;
  int *index;
  _Tp *keys;
};

template <typename _Tp> IndexMaxPQ<_Tp>::IndexMaxPQ(int NMAX)
    : pq(new int[NMAX + 1]), index(new int[NMAX + 1]), keys(new _Tp[NMAX+1]),
      n(0) {
  for (int i = 0; i <= NMAX; ++i) {
    index[i] = -1;
  }
}

template <typename _Tp> IndexMaxPQ<_Tp>::~IndexMaxPQ<_Tp>() {
  delete[] pq;
  delete[] index;
  delete[] keys;
}

template <typename _Tp> void IndexMaxPQ<_Tp>::insert(int k, _Tp key) {
  pq[++n] = k;
  index[k] = n;
  keys[k] = key;
  bubbleUp(n);
}

template <typename _Tp> int IndexMaxPQ<_Tp>::deleteMax() {
  auto maxIndex = pq[n];
  swap(1, n--);
  bubbleDown(1);
  index[maxIndex] = -1;
  // pq[n+1] = -1;
  return maxIndex;
}

template <typename _Tp> void IndexMaxPQ<_Tp>::changeKey(int k, _Tp key) {
  keys[k] = key;
  bubbleUp(index[k]);
  bubbleDown(index[k]);
}

template <typename _Tp> void IndexMaxPQ<_Tp>::deleteKey(int k) {
  auto ind =index[k];
  swap(ind, n--);
  bubbleUp(ind);
  bubbleDown(ind);
  index[k] = -1;
}

template <typename _Tp> void IndexMaxPQ<_Tp>::bubbleUp(int k) {
  while (k > 1 && less(keys[pq[k/2]], keys[pq[k]])) {
    swap(k/2, k);
    k /= 2;
  }
}

template <typename _Tp> void IndexMaxPQ<_Tp>::bubbleDown(int k) {
  int j;
  while (2*k <= n) {
    j = 2*k;
    if (j+1 <= n && less(keys[pq[j]], keys[pq[j+1]])) {
      ++j;
    }
    if (!less(keys[pq[k]], keys[pq[j]])) {
      break;
    }
    swap(k, j);
    k = j;
  }
}

template <typename _Tp> void IndexMaxPQ<_Tp>::swap(int i, int j) {
  auto temp = pq[i];
  pq[i] = pq[j];
  pq[j] = temp;

  index[pq[i]] = i;
  index[pq[j]] = j;
}

#endif /* INDEXMAXPQ_H */
