/* Modfy binary search so that it always returns the element with the smallest */
/* index that matches the search element (and still guarantees logarithmic running */
/* time). */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

int rank(const int &value, const std::vector<int> &v) {
  auto head = 0;
  auto tail = v.size() - 1;

  while (head <= tail) {
    auto mid = head + (tail - head) / 2;
    if (value > v[mid]) {
      tail = mid - 1;
    } else if (value < v[mid] || (mid > 0 && v[mid-1] == value)) {
      head = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  auto pv = std::make_shared<std::vector<int>>();
  pv->reserve(1000);

  auto temp = 0;
  while (std::cin >> temp) {
    pv->push_back(temp);
  }

  std::sort(pv->begin(), pv->end());

  std::cout << rank(2, *pv) << std::endl;
}
