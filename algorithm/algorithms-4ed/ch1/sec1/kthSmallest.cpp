#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  auto val = 0;
  std::vector<int> vec;
  while (std::cin >> val) {
    vec.push_back(val);
  }

  std::sort(vec.begin(), vec.end());
  auto pivot = std::unique(vec.begin(), vec.end());
  vec.erase(pivot, vec.end());
}
