#ifndef QUICK_H
#define QUICK_H

#include <cstddef>
#include <vector>
#include <algorithm>

template <typename _Tp> class Quick {
public:
  void sort(std::vector<_Tp> &);

private:
  void sort(std::vector<_Tp> &a, size_t lo, size_t hi);
  size_t partition(std::vector<_Tp> &a, size_t lo, size_t hi);
};

template <typename _Tp> void Quick<_Tp>::sort(std::vector<_Tp> &a) {
  size_t maxIndex = std::max_element(a.begin(), a.end()) - a.begin();
  /* auto max = a[0]; */
  /* auto maxIndex = 0; */

  /* for (const auto& i : a) { */
  /*   if (i > max) { */
  /*     max = a[i]; */
  /*     maxIndex = i; */
  /*   } */
  /* } */
  
  
  std::swap(a[a.size() - 1], a[maxIndex]);
  sort(a, 0, a.size() - 1);
}

template <typename _Tp>
inline void Quick<_Tp>::sort(std::vector<_Tp>& a, size_t lo, size_t hi) {
  if (hi <= lo) { return; }

  auto pivot = partition(a, lo, hi);
  sort(a, lo, pivot - 1);
  sort(a, pivot + 1, hi);
}

template <typename _Tp>
size_t Quick<_Tp>::partition(std::vector<_Tp>& a, size_t lo, size_t hi) {
  auto val = a[lo];

  size_t p = lo;
  size_t q = hi + 1;
  
  while (true) {
    while (a[++p] < val) {
      continue;
    }
    while (a[--q] > val) {
      continue;
    }
    if (p >= q) {
      break;
    }
    std::swap(a[p], a[q]);
  }
  std::swap(a[lo], a[q]);

  return q;
}

#endif /* QUICK_H */
