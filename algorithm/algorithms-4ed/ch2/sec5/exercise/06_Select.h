#include <algorithm>
#include <random>
#include <vector>

template <typename _Tp> class Select {
public:
  _Tp select(std::vector<_Tp> &a, int k);

private:
  _Tp recursiveSelect(std::vector<_Tp> &a, int k, int lo, int hi);
  int partition(std::vector<_Tp> &a, int lo, int hi);
};

template <typename _Tp> _Tp Select<_Tp>::select(std::vector<_Tp> &a, int k) {
  return recursiveSelect(a, k, 0, a.size() - 1);
}

template <typename _Tp>
_Tp Select<_Tp>::recursiveSelect(std::vector<_Tp> &a, int k, int lo, int hi) {
  if (lo == hi) { return lo; }
  int pivot = partition(a, lo, hi);
  if (pivot == k) {
    return a[k];
  } else {
    if (pivot < k) {
      return recursiveSelect(a, k, pivot + 1, hi);
    } else {
      return recursiveSelect(a, k, lo, pivot - 1);
    }
  }
}

template <typename _Tp>
int Select<_Tp>::partition(std::vector<_Tp> &a, int lo, int hi) {
  auto p = lo;
  auto q = hi + 1;
  auto val = a[lo];

  while (true) {
    while (a[++p] < val)
      if (p == hi)
        break;
    while (val < a[--q])
      if (q == lo)
        break;
    if (p >= q)
      break;
    std::swap(a[p], a[q]);
  }
  std::swap(a[lo], a[q]);
  return q;
}
