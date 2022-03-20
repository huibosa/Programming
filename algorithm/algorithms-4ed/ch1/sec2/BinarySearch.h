#pragma once

#include "Counter.h"
#include <iostream>
#include <vector>
#include <algorithm>

class BinarySearch {
public:
  BinarySearch() = default;

public:
  int rank(const int &value, const std::vector<int> &v, Counter& counter);
};

inline int rank(const int &value, const std::vector<int> &v, Counter &counter) {
  std::sort(v.begin(), v.end());
  auto head = 0;
  auto tail = v.size() - 1;

  while (head <= tail) {
    counter.increment();
    auto mid = head + (tail - head) / 2;
    if (value < v[mid]) {
      tail = mid - 1;
    } else if (value > v[mid]) {
      head = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}
