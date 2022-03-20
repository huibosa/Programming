/* 1.4.2 Modify ThreeSum to work properly even when the int values are so large that */
/* adding two of them might cause overflow. */

#include <cstddef>
#include <iostream>
#include <vector>

std::size_t count(const std::vector<std::size_t>& a) {
  std::size_t size = a.size();
  std::size_t cnt = 0;

  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = i + 1; j < size; ++j) {
      for (std::size_t k = j + 1; k < size ; ++k) {
        if (a[i] + a[j] + a[k] == 0) {
          cnt++;
        }
      }
    }
  }
  return cnt;
}

int main() {
  std::vector<std::size_t> a;

  std::size_t temp = 0;
  while (std::cin >> temp) {
    a.push_back(temp);
  }

  std::cout << count(a) << std::endl;

  return 0;
}
