#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename _Tp> class Merge {
public:
  void sort(std::vector<_Tp> &a);

private:
  void sort(std::vector<_Tp> &a, std::vector<_Tp> &aux, int lo, int hi);
  void merge(std::vector<_Tp> &a, std::vector<_Tp> &aux, int lo, int mid,
             int hi);
};

template <typename _Tp> inline void Merge<_Tp>::sort(std::vector<_Tp> &a) {
  std::vector<_Tp> aux;
  aux.reserve(a.size());
  sort(a, aux, 0, a.size() - 1);
}

template <typename _Tp>
inline void Merge<_Tp>::sort(std::vector<_Tp> &a, std::vector<_Tp> &aux, int lo,
                             int hi) {
  if (hi <= lo) {
    return;
  }

  auto mid = lo + (hi - lo) / 2;
  sort(a, aux, lo, mid);
  sort(a, aux, mid + 1, hi);
  merge(a, aux, lo, mid, hi);
}

template <typename _Tp>
void Merge<_Tp>::merge(std::vector<_Tp> &a, std::vector<_Tp> &aux, int lo,
                       int mid, int hi) {

  for (int i = lo; i <= hi; ++i) {
    aux[i] = a[i];
  }

  auto i = lo;
  auto p = lo;
  auto q = mid + 1;

  while (p <= mid && q <= hi) {
    if (aux[p] < aux[q]) {
      a[i++] = aux[p++];
    } else {
      a[i++] = aux[q++];
    }
  }

  while (p <= mid) {
    a[i++] = aux[p++];
  }
  
  while (q <= hi) {
    a[i++] = aux[q++];
  }
}
