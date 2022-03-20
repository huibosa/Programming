#include <iostream>
#include <vector>
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"

int main() {
  std::vector<double> nums;
  for (auto temp = 0; std::cin >> temp;) {
    nums.push_back(temp);
  }

  Shell<double> shell;
  shell.sort(nums);
  assert(shell.isSorted(nums));
  shell.show(nums);

  return 0;
}
