#include "Heap.h"
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> a;
  for (int i = 0; i < 10; ++i) {
    a.push_back(rand() % 100);
  }

  Heap<int> heap;
  heap.sort(a);

  for (const auto& i : a) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
