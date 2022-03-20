#include <iostream>
#include "MergeBU.h"
#include "MergeTD.h"


int main() {
  std::vector<int> a{ 1,2,3,5,61,2,4,5,6,7,1,2,3,4,1,2,4,6,7,8,9 };
  MergeBU<int> merge;
  merge.sort(a);
  std::for_each(a.begin(), a.end(), [](const int n) { std::cout << n << " "; });

  return 0;
}
