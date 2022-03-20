#ifndef QUICK_H
#define QUICK_H

#include <cstddef>
#include <utility>
#include <vector>
#include <functional>

template<typename _Tp> class Quick {
public:
  void sort(std::vector<_Tp>& a);
private:
  void sort(std::vector<_Tp>& a, size_t lo, size_t hi);
  size_t partition(std::vector<_Tp>& a, size_t l, size_t hi);
};


template<typename _Tp>
inline void Quick<_Tp>::sort(std::vector<_Tp>& a, size_t lo, size_t hi) {
  if (hi <= lo) { return; }

  auto j = partition(a, lo, hi);
  sort(a, lo, j-1);
  sort(a, j+1, hi);
}


template<typename _Tp>
size_t Quick<_Tp>::partition(std::vector<_Tp>& a, size_t lo, size_t hi) {
  auto i = lo;
  auto j = hi + 1;
  auto v = a[lo];

  while (true) {
    while (std::less<_Tp>{}(a[++i], v)) {
      if (i == hi) { break; }
    }
    while (std::less<_Tp>{}(v, a[--j])) {
      if (j == lo) { break; }
    }
    if (i >= j) {
      break;
    }
    std::exchange(a[i], a[j]);
  }
  std::exchange(a[lo], a[j]);
  return j;
}


#endif /* QUICK_H */
