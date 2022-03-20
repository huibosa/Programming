/* 1.1.15 Write a static method histogram() that takes an array a[] of int values and */
/* an integer M as arguments and returns an array of length M whose ith entry is the num- */
/* ber of times the integer i appeared in the argument array. If the values in a[] are all */
/* between 0 and M–1, the sum of the values in the returned array should be equal to */
/* a.length. */

#include <iostream>
#include <vector>
#include <memory>

auto histogram(std::vector<int>& v, int m) {
  auto pv = new std::vector<int>(6);
  for (const auto& i : v) {
      pv->at(i)++;
  }

  return pv;
}

int main() {
  std::vector<int> v{0,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};

  auto pv = histogram(v, 10);
  for (const auto& i : *pv) {
      std::cout << i << " ";
  }
  delete pv;
  std::cout << std::endl;


  return 0;
}
