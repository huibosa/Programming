#ifndef QUICK_H
#define QUICK_H

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <type_traits>
#include <vector>
#include <set>

template <typename _Tp> class Quick {
public:
  void sort(std::vector<_Tp> &);

private:
  void sort(std::vector<_Tp> &a, size_t lo, size_t hi);
  size_t partition(std::vector<_Tp> &a, size_t lo, size_t hi);
  size_t getMedianIndex(std::vector<_Tp>& a, size_t lo, size_t hi);
  std::vector<_Tp> getRandomIndexes(size_t lo, size_t hi);
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
std::vector<_Tp> Quick<_Tp>::getRandomIndexes(size_t lo, size_t hi) {
  auto range = hi - lo;
  std::set<_Tp> set;
  
  while (set.size() < 5) {
    set.insert(rand() % range);
  }

  return {set.begin(), set.end()};
}


template <typename _Tp>
size_t Quick<_Tp>::getMedianIndex(std::vector<_Tp>& vec, size_t lo, size_t hi) {
  if (hi - lo + 1 < 5) {
    return lo;
  }
  
  auto entries = getRandomIndexes(lo, hi);
  
  auto& a = entries[0];
  auto& b = entries[1];
  auto& c = entries[2];
  auto& d = entries[3];
  auto& e = entries[4];

  if (vec[a] > vec[b]) {
    std::swap(vec[a], vec[b]);
  }
  if (vec[c] > vec[d]) {
    std::swap(vec[c], vec[d]);
  }

  if (vec[a] > vec[c]) {
    std::swap(vec[a], vec[c]);
    std::swap(vec[b], vec[d]);
  }

  vec[a] = vec[e];

  if (vec[a] > vec[b]) {
    std::swap(vec[a], vec[b]);
  }

  if (vec[a] > vec[c]) {
    std::swap(vec[a], vec[c]);
    std::swap(vec[b], vec[d]);
  }

  return (vec[b] > vec[c] ? c : b);
}

template <typename _Tp>
size_t Quick<_Tp>::partition(std::vector<_Tp>& a, size_t lo, size_t hi) {

  auto midian = getMedianIndex(a, lo, hi);
  std::swap(a[lo], a[midian]);
  
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
