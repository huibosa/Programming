#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename _Tp> class MergeBU {
public:
  void sort(std::vector<_Tp> &a);
  void merge(std::vector<_Tp> &a, int lo, int mid, int hi);

private:
  std::vector<_Tp> aux;
};

template <typename _Tp>
void MergeBU<_Tp>::merge(std::vector<_Tp> &a, int lo, int mid, int hi) {
  auto i = lo;
  auto j = mid + 1;

  for (int k = lo; k <= hi; ++k) {
    aux[k] = a[k];
  }

  for (int k = lo; k <= hi; ++k) {
    if (i > mid) { // left half exhausted
      a[k] = aux[j++];
    } else if (j > hi) { // right half exhausted
      a[k] = aux[i++];
    } else if (std::less<_Tp>{}(aux[j], aux[i])) { // current key on right
      a[k] = aux[j++]; // less than current key on left
    } else { // current key on right greater than or equal to current key on
             // left
      a[k] = aux[i++];
    }
  }
}

template <typename _Tp> inline void MergeBU<_Tp>::sort(std::vector<_Tp> &a) {
  const int n = a.size();
  aux.reserve(n);

  for (auto sz = 1; sz < n; sz = sz + sz) {
    for (int lo = 0; lo < n - sz; lo += sz + sz) {
      merge(a, lo, lo + sz - 1, std::min(lo + sz + sz - 1, n - 1));
    }
  }
}
