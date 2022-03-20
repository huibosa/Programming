#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

template<typename _Tp> class MergeTD {
public:
  void sort(std::vector<_Tp>& a);
  void sort(std::vector<_Tp>& a, int lo, int hi);
  void merge(std::vector<_Tp>& a, int lo, int mid, int hi);
private:
  std::vector<_Tp> aux;
};


template<typename _Tp>
inline void MergeTD<_Tp>::sort(std::vector<_Tp> &a) {
  aux.reserve(a.size());
  sort(a, 0, a.size() - 1);
}


template<typename _Tp>
inline void MergeTD<_Tp>::sort(std::vector<_Tp> &a, int lo, int hi) {
  if (hi <= lo) {
    return;
  }
  
  auto mid = lo + (hi - lo)/2;
  sort(a, lo, mid);
  sort(a, mid+1, hi);
  merge(a, lo, mid, hi);
}


template<typename _Tp>
void MergeTD<_Tp>::merge(std::vector<_Tp> &a, int lo, int mid, int hi) {
  auto i = lo;
  auto j = mid + 1;

  for (int k = lo; k <= hi; ++k) {
    aux[k] = a[k];
  }

  for (int k = lo; k <= hi; ++k) {
    if (i > mid) {        // left half exhausted
      a[k] = aux[j++];
    } else if (j > hi) {  // right half exhausted
      a[k] = aux[i++];
    } else if (std::less<int>{}(aux[j], aux[i])) {  // current key on right
      a[k] = aux[j++];                              // less than current key on left
    } else {      // current key on right greater than or equal to current key on left
      a[k] = aux[i++];
    }
  }
}
