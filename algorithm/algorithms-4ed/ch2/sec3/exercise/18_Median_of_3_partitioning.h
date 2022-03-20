#ifndef QUICK_H
#define QUICK_H

#include <cstddef>
#include <vector>

template <typename _Tp> class Quick {
public:
  void sort(std::vector<_Tp> &);

private:
  void sort(std::vector<_Tp> &a, size_t lo, size_t hi);
  size_t partition(std::vector<_Tp> &a, size_t lo, size_t hi);
  size_t getMedianIndex(std::vector<_Tp>& a, size_t lo, size_t hi);
};

template <typename _Tp> inline void Quick<_Tp>::sort(std::vector<_Tp> &a) {
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
size_t Quick<_Tp>::getMedianIndex(std::vector<_Tp>& a, size_t lo, size_t hi) {
  auto mid = lo + (hi - lo) / 2;

  if (a[mid] < a[lo]) {
    std::swap(a[mid], a[lo]);
  }
  if (a[hi] < a[lo]) {
    std::swap(a[hi], a[mid]);
  }
  if (a[hi] < a[mid]) {
    std::swap(a[hi], a[mid]);
  }
  
  return mid;
}

template <typename _Tp>
size_t Quick<_Tp>::partition(std::vector<_Tp>& a, size_t lo, size_t hi) {
  auto mid = getMedianIndex(a, lo, hi);
  std::swap(a[lo], a[mid]);
  
  auto pivot = a[lo];

  size_t p = lo;
  size_t q = hi + 1;
  
  while (true) {
    while (a[++p] < pivot) {
      continue;
    }
    while (a[--q] > pivot) {
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
