/* 2.1.20  Shellsort best case. What is the best case for shellsort? Justify your answer. */

#include <cstdint>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "ShellSortWithCompareCount.h"

std::vector<double> initRandomArray(int n) {
  std::vector<double> ret;
  
  for (int i = 0; i < n; ++i) {
    ret.push_back(i);
  }

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(ret.begin(), ret.end(), g);

  return ret;
}
std::vector<double> initReverseArray(int n) {
  std::vector<double> ret;
  
  srand(time(0));
  for (int i = n; i > 0; --i) {
    ret.push_back(i);
  }

  return ret;
}

std::vector<double> initSortedArray(int n) {
  std::vector<double> ret;
  
  srand(time(0));
  for (int i = n; i > 0; --i) {
    ret.push_back(i);
  }

  return ret;
}

std::vector<double> findBestCaseInput(int n) {
  std::vector<double> bestCaseArray;
  int lowestNumberOfCompares = INT32_MAX;

  for (int i = 0; i < n; ++i) {
    ShellSortWithCompareCount shell;
    std::vector<double> a = initRandomArray(100);
    auto copy = a;
    shell.sort(copy);

    if (shell.getCompareCount() < lowestNumberOfCompares) {
      bestCaseArray = a;
      lowestNumberOfCompares = shell.getCompareCount();
    }
    std::cout << "Tries: " << i << ", ";
    std::cout << "Lowest number of compares: " << lowestNumberOfCompares << "\n";
  }

  
  return bestCaseArray;
}

int main() {
  auto worstCaseArray = findBestCaseInput(100000000);

  std::copy(worstCaseArray.begin(), worstCaseArray.end(),
      std::ostream_iterator<double>(std::cout, ","));

  return 0;
}
