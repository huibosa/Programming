#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <iostream>

template <typename _Tp>
static inline void sort(_Tp& i, _Tp& j) {
  if (i > j) {
    std::swap(i, j);
  }
}

template <typename _Tp>
_Tp getMedian5(_Tp& a, _Tp& b, _Tp& c, _Tp& d, _Tp& e) {
  if (a > b) {
    std::swap(a, b);
  }
  if (c > d) {
    std::swap(c, d);
  }
  if (a > c) {
    std::swap(a, c);
    std::swap(b, d);
  }
  a = e;

  if (a > b) {
    std::swap(a, b);
  }
  if (a > c) {
    std::swap(a, c);
    std::swap(b, d);
  }

  return std::min(b, c);
}

template <typename _Tp> inline _Tp getMedian5(std::array<_Tp, 5> &a) {
  return getMedian5(a[0], a[1], a[2], a[3], a[4]);
}

int main() {
  srand(time(0));
  const int n = 5;
  std::array<int, 5> a;
  
  while (getchar() == '\n') {
    for (int i = 0; i <= n; ++i) {
      a[i] = rand() % n + 1;
    }
    std::sort(a.begin(), a.end());

    std::cout << "Array: ";
    for (const auto& i : a) {
      std::cout << i << " ";
    }
    std::cout << "\n";


    std::cout << "Median: " << getMedian5(a);
  }

  return 0;
}
