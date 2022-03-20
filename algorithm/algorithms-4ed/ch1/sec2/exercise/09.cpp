#include "BinarySearch.h"
#include "Counter.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  Counter counter;
  BinarySearch bs;

  std::vector<int> v;
  int temp;
  while (std::cin >> temp) {
    v.push_back(temp);
  }

  std::sort(v.begin(), v.end());
  bs.rank(48, v, counter);

  std::cout << counter.toString() << std::endl;
}
