#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename _Tp> _Tp select(const std::vector<_Tp>& a, int k) {
  std::random_device rd;
  std::mt19937 rg(rd());
  
  std::shuffle(a.begin(), a.end(), rg);

  size_t lo = 0;
  size_t hi = a.size() - 1;
  
  while (hi > lo) {
    
  }
}
