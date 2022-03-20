/* 2.1.19  Shellsort worst case. Construct an array of 100 elements containing the num- */
/* bers 1 through 100 for which shellsort, with the increments 1 4 13 40, uses as large a */ 
/* number of compares as you can find. */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "ShellSortWithCompareCount.h"

std::vector<double> initRandomArray() {
  std::vector<double> ret;
  
  ret.reserve(100);
  for (int i = 0; i < 100; ++i) {
    ret.push_back(i);
  }

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(ret.begin(), ret.end(), g);

  return ret;
}

std::vector<double> initReverseArray(int n) {
  std::vector<double> ret;
  
  for (int i = 100 - 1; i >= 0; --i) {
    ret.push_back(i);
  }

  return ret;
}

std::vector<double> initSortedArray() {
  std::vector<double> ret;
  
  for (int i = 0; i < 100; ++i) {
    ret.push_back(i);
  }

  return ret;
}

std::vector<double> findWorstCaseInput(int n) {
  std::vector<double> worstCaseArray;
  int highestNumberOfCompares = 0;

  for (int i = 0; i < n; ++i) {
    ShellSortWithCompareCount<double> shell;
    std::vector<double> a = initRandomArray();
    auto copy = a;
    shell.sort(copy);

    if (shell.getCompareCount() > highestNumberOfCompares) {
      worstCaseArray = a;
      highestNumberOfCompares = shell.getCompareCount();
    }
    std::cout << "Tries: " << i << ", ";
    std::cout << "Highest number of compares: " << highestNumberOfCompares << "\n";
  }

  
  return worstCaseArray;
}

int main() {
  auto worstCaseArray = findWorstCaseInput(100000000);

  std::copy(worstCaseArray.begin(), worstCaseArray.end(),
      std::ostream_iterator<double>(std::cout, ","));

  return 0;
}
