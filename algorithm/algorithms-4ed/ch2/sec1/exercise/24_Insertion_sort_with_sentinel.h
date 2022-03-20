/* 2.1.24  Insertion sort with sentinel. Develop an implementation of insertion sort that */ 
/* eliminates the j>0 test in the inner loop by first putting the smallest item into position. */ 
/* Use SortCompare to evaluate the effectiveness of doing so. Note : It is often possible to */ 
/* avoid an index-out-of-bounds test in this way—the element that enables the test to be */ 
/* eliminated is known as a sentinel. */


#include <functional>
#include <iostream>
#include <vector>
#include <cassert>
#include <limits>

template<typename _Tp>
class Sentinel {
public:
  void sort(std::vector<_Tp>& a);
  bool isSorted(const std::vector<_Tp>& a) const;
  void show(const std::vector<_Tp>& a) const;
private:
  bool less(_Tp v, _Tp w) const;
  void exch(std::vector<_Tp>& a, int i, int j);
};

template<typename _Tp>
inline void Sentinel<_Tp>::exch(std::vector<_Tp>& a, int i, int j) {
  auto tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

template<typename _Tp>
inline void Sentinel<_Tp>::show(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
};

template<typename _Tp>
inline bool Sentinel<_Tp>::less(_Tp v, _Tp w) const {
  std::less<_Tp> less;
  return less(v, w);
};

template<typename _Tp>
inline bool Sentinel<_Tp>::isSorted(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    if (less(a[i], a[i-1])) {
      return false;
    }
  }
  return true;;
}

template<typename _Tp>
inline void Sentinel<_Tp>::sort(std::vector<_Tp>& a) {
  auto minimumEntry = std::numeric_limits<_Tp>::max();

  int minimumIndex = -1;

  for (int i = 0; i < a.size(); ++i) {
    if (less(a[i], minimumEntry)) {
      minimumEntry = a[i];
      minimumIndex = i;
    }
  }

  // move smallest element to the first position
  exch(a, 0, minimumIndex);

  for (int i = 1; i < a.size(); ++i) {
    for (int j = i; a[j] < a[j-1]; --j) {
      exch(a, j, j-1);
    }
  }
}
