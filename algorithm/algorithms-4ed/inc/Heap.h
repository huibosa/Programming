#ifndef HEAP_H
#define HEAP_H

#include <cstddef>
#include <functional>
#include <vector>

template <typename _Tp> class Heap {
public:
  void sort(std::vector<_Tp>& a);
private:
  void sink(std::vector<_Tp>& a, size_t k, size_t b);
  void swap(std::vector<_Tp>& a, size_t i, size_t j);
  bool less(std::vector<_Tp>& a, size_t i, size_t j);
};

template <typename _Tp>
void Heap<_Tp>::swap(std::vector<_Tp>& a, size_t i, size_t j) {
  auto temp = a[i-1];
  a[i-1] = a[j-1];
  a[j-1] = temp;
}

template <typename _Tp>
bool Heap<_Tp>::less(std::vector<_Tp>& a, size_t i, size_t j) {
  return a[i-1] < a[j-1];
}

template <typename _Tp>
void Heap<_Tp>::sink(std::vector<_Tp>& a, size_t k, size_t b) {
  while (2*k <= b) {
    size_t j = 2*k;
    if (j < b && less(a, j, j+1)) {
      ++j;
    }
    if (!less(a, k, j)) {
      break;
    }
    swap(a, k, j);
    k = j;
  }
}

template <typename _Tp> void Heap<_Tp>::sort(std::vector<_Tp>& a) {
  size_t n = a.size();
  for (int k = n/2; k >= 1; --k) {
    sink(a, k, n);
  }
  while (n > 1) {
    swap(a, 1, n--);
    sink(a, 1, n);
  }
}

#endif /* HEAP_H */
