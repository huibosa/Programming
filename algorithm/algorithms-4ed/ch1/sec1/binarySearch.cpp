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

int main(int argc, char *argv[]) {
  std::fstream input(argv[1]);
  auto pv = std::make_shared<std::vector<int>>();
  pv->reserve(1000);

  auto temp = 0;
  while (input >> temp) {
    pv->push_back(temp);
  }
  double push_time = static_cast<double>(clock()) / CLOCKS_PER_SEC;

  std::sort(pv->begin(), pv->end());
  double sort_time = static_cast<double>(clock()) / CLOCKS_PER_SEC - push_time;

  std::cout << rank(499569, *pv) << std::endl;
  double rank_time = static_cast<double>(clock()) / CLOCKS_PER_SEC - sort_time;

  std::cout << "push time: " << push_time << std::endl;
  std::cout << "sort time: " << sort_time << std::endl;
  std::cout << "rank time: " << rank_time << std::endl;
}
