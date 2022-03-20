#include <algorithm>
#include <random>
#include <vector>

template <typename _Tp> class Select {
public:
  _Tp select(std::vector<_Tp>& a, int k);
private:
  int partition(std::vector<_Tp>& a, int lo, int hi);
};

template <typename _Tp> int Select<_Tp>::partition(std::vector<_Tp> &a, int lo, int hi) {
  auto p = lo;
  auto q = hi+1;
  auto val = a[lo];

  while (true) {
    while (a[++p] < val) if (p == hi) break;
    while (val < a[--q]) if (q == lo) break;
    if (p >= q) break;
    std::swap(a[p], a[q]);
  }
  std::swap(a[lo], a[q]);
  return q;
}

template <typename _Tp> _Tp Select<_Tp>::select(std::vector<_Tp> &a, int k) {
  int lo = 0;
  int hi = a.size() - 1;

  while (hi > lo) {
    int pivot = partition(a, lo, hi);
    if     (pivot == k) return a[k];
    else if (pivot > k) hi = pivot - 1;
    else if (pivot < k) lo = pivot + 1;
  }

  return a[k];
}
