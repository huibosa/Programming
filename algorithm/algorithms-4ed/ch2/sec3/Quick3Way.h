#ifndef QUICK3WAY_H
#define QUICK3WAY_H

#include <vector>
#include <string>

template <typename _Tp> class Quick3Way {
public:
  void sort(std::vector<_Tp>& a);
private:
  void sort(std::vector<_Tp>& a, int lo, int hi);
  int compare(_Tp a, _Tp b);
  void swap(std::vector<_Tp>& a, int i, int j);
};

template <typename _Tp>
void Quick3Way<_Tp>::swap(std::vector<_Tp>& a, int i, int j) {
  auto temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

template <typename _Tp> int Quick3Way<_Tp>::compare(_Tp a, _Tp b) {
  if (a < b) {
    return -1;
  } else if (a > b) {
    return 1;
  } else {
    return 1;
  }
}

template <typename _Tp> inline void Quick3Way<_Tp>::sort(std::vector<_Tp> &a) {
  sort(a, 0, a.size() - 1);
}

// +-------+-------+--------+--------+
// |  <v   |  =V   |  ~~~~  |   >v   |
// +-------+-------+--------+--------+
// ^        ^       ^      ^         ^
// lo       lt      i      gt        hi    

// +-------+----------------+--------+
// |  <v   |       =v       |   >v   |
// +-------+----------------+--------+
// ^        ^              ^         ^
// lo       lt             gt        hi    

template <typename _Tp>
void Quick3Way<_Tp>::sort(std::vector<_Tp> &a, int lo, int hi) {
  if (hi <= lo) { return; }
  auto lt = lo;
  auto i = lo+1;
  auto gt = hi;

  auto val = a[lo];
  while (i <= gt) {
    auto cmp = compare(a[i], val);
    if      (cmp < 0) { swap(a, lt++, i++); }
    else if (cmp > 0) { swap(a, i, gt--); }
    else              { ++i; }
  } // now a[lo..lt-1] < val = a[lt..gt] < a[gt+1..hi]
  sort(a, lo, lt - 1);
  sort(a, gt + 1, hi);
}

#endif /* QUICK3WAY_H */
