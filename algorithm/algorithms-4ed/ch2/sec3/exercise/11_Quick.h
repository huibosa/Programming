#ifndef QUICK_H
#define QUICK_H

#include <cstddef>
#include <vector>

template <typename _Tp> class Quick {
public:
  void sort(std::vector<_Tp> &);

private:
  void sort(std::vector<_Tp> &a, int lo, int hi);
  int partition(std::vector<_Tp> &a, int lo, int hi);
};

template <typename _Tp> inline void Quick<_Tp>::sort(std::vector<_Tp> &a) {
  sort(a, 0, a.size() - 1);
}

template <typename _Tp>
inline void Quick<_Tp>::sort(std::vector<_Tp>& a, int lo, int hi) {
  if (hi <= lo) { return; }

  int pivot = partition(a, lo, hi);
  sort(a, lo, pivot - 1);
  sort(a, pivot + 1, hi);
}

template <typename _Tp>
int Quick<_Tp>::partition(std::vector<_Tp>& a, int lo, int hi) {
  auto val = a[lo];

  int p = lo;
  int q = hi+1;
  
  while (true) {
    while (a[++p] <= val) if (p == hi) break;
    while (a[--q] >= val) if (q == lo) break;
    if (p >= q) break;
    std::swap(a[p], a[q]);
  }
  std::swap(a[lo], a[q]);

  return q;
}

#endif /* QUICK_H */
