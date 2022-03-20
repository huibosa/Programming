#ifndef QUICK_H
#define QUICK_H

#include <cstddef>
#include <vector>
#include "Insertion.h"

/* template <typename _Tp> class Insertion; */

template <typename _Tp> class QuickInsertion {
/* friend class Insertion<_Tp>; */
public:
  void sort(std::vector<_Tp> &);

private:
  void sort(std::vector<_Tp> &a, size_t lo, size_t hi);
  size_t partition(std::vector<_Tp> &a, size_t lo, size_t hi);
  Insertion<_Tp> insertion;
};

template <typename _Tp> inline void QuickInsertion<_Tp>::sort(std::vector<_Tp> &a) {
  sort(a, 0, a.size() - 1);
}

template <typename _Tp>
inline void QuickInsertion<_Tp>::sort(std::vector<_Tp>& a, size_t lo, size_t hi) {
  if (hi <= lo) {
    insertion.sort(a, lo, hi);
    return; 
  }

  auto pivot = partition(a, lo, hi);
  sort(a, lo, pivot - 1);
  sort(a, pivot + 1, hi);
}

template <typename _Tp>
size_t QuickInsertion<_Tp>::partition(std::vector<_Tp>& a, size_t lo, size_t hi) {
  auto val = a[lo];

  size_t p = lo;
  size_t q = hi + 1;
  
  while (true) {
    while (a[++p] < val && p < hi) {
      continue;
    }
    while (a[--q] > val && q > lo) {
      continue;
    }
    if (p >= q) {
      break;
    }
    std::swap(a[p], a[q]);
  }
  std::swap(a[lo], a[p]);

  return p;
}

#endif /* QUICK_H */
