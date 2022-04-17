#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

template <typename _Tp>
std::vector<std::vector<_Tp>> groupVector(const std::vector<_Tp> &arr,
                                          size_t n) {
  if (arr.size() == 0 || n == 0 || n > arr.size() || arr.size() == n) {
    return std::vector<std::vector<_Tp>>();
  }

  const auto N = arr.size();
  
  std::vector<_Tp> subArr;
  std::vector<std::vector<_Tp>> ret;
  
  // (0 1 2 3) (4 5 6 7) (8 9 10 11) (12 13 14 15) (16 17 18 19) 20 21
  for (size_t i = 0; i < N; ++i) {
    subArr.push_back(arr[i]);
    
    if (subArr.size() == n) {
      ret.push_back(subArr);
      subArr.resize(0);
    }
  }
  
  if (subArr.size() != 0) {
    ret.push_back(subArr);
  }

  return ret;
}

int main() {
  std::vector<int> arr;
  for (int i = 0; i < 100000000; ++i) {
    arr.push_back(i);
  }

  auto res = groupVector(arr, 2);

  /* for (const auto& subArr : res) { */
  /*   for (const auto& i : subArr) { */
  /*     std::cout << i << " "; */
  /*   } */
  /*   std::cout << "\n"; */
  /* } */

  return 0;
}
