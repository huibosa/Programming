#include <cstdlib>
#include <iostream>
#include <vector>
#include "09_Merge.h"

int main() {
  std::vector<int> a;
  for (int i = 0; i < 10; ++i) {
    a.push_back(rand() % 10);
  }

  Merge<int> merge;
  merge.sort(a);

  for (const auto& i : a) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
