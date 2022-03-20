#ifndef MERGEIMPROVE_H
#define MERGEIMPROVE_H

#include "Insertion.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename _Tp> class MergeImprove {
public:
  void sort(std::vector<_Tp> &a);
  void sort(std::vector<_Tp> &a, std::vector<_Tp> &aux, int lo, int hi);
  void merge(std::vector<_Tp> &a, std::vector<_Tp> &aux, int lo, int mid,
             int hi);

private:
  const unsigned CUTOFF = 15;
  Insertion<_Tp> insertion;
};

template <typename _Tp>
inline void MergeImprove<_Tp>::sort(std::vector<_Tp> &a) {
  auto aux = a;
  sort(a, aux, 0, a.size() - 1);
}

template <typename _Tp>
inline void MergeImprove<_Tp>::sort(std::vector<_Tp> &a, std::vector<_Tp> &aux,
                                    int lo, int hi) {
  /* if (hi - lo <= CUTOFF) { */
  /*   insertion.sort(aux, lo, hi); */
  /*   return; */
  /* } */
  if (hi <= lo) { return; }

  auto mid = lo + (hi - lo) / 2;
  sort(aux, a, lo, mid);
  sort(aux, a, mid + 1, hi);

  /* if (a[mid] <= a[mid + 1]) { */
  /*   for (int i = lo; i <= hi; ++i) { */
  /*     a[i] = aux[i]; */
  /*   } */
  /*   return; */
  /* } */

  merge(aux, a, lo, mid, hi);
}

template <typename _Tp>
void MergeImprove<_Tp>::merge(std::vector<_Tp> &a, std::vector<_Tp> &aux,
                              int lo, int mid, int hi) {
  auto p = lo;
  auto q = mid + 1;

  for (int i = lo; i <= hi; ++i) {
    if (p > mid) { // left half exhausted
      aux[i] = a[q++];
    } else if (q > hi) { // right half exhausted
      aux[i] = a[p++];
    } else if (std::less<int>{}(a[q], a[p])) { // current key on right
      aux[i] = a[q++]; // less than current key on left
    } else { // current key on right greater than or equal to current key on
             // left
      aux[i] = a[p++];
    }
  }
}

#endif /* MERGEIMPROVE_H */
