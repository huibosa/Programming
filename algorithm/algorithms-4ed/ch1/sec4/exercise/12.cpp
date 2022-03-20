/* Write a proram that, given two sorted arrays of N int values, prints all ele- */
/* ments that appear in both arrays, in sorted order. The running time of your program */
/* should be proportional to N in the worst case. */

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

void printDuplicates(std::vector<int> &v1, std::vector<int> &v2) {
  v1.insert(v1.end(), v2.cbegin(), v2.cend());
  std::sort(v1.begin(), v1.end());

  for (auto iter = v1.cbegin(); iter != v1.cend(); ++iter) {
    if (*iter == *(iter + 1)) {
      std::cout << *iter << " ";
      ++iter;
    }
  }
  std::cout << "\n";
}

int main() {
  // the output should be (2,6,8,9)
  std::vector<int> v1{1, 2, 6, 8, 8, 7, 9}; // 1,2,6,7,8,9
  std::vector<int> v2{2, 2, 6, 5, 4, 8, 9}; // 2,4,5,6,8,9

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  auto end1 = std::unique(v1.begin(), v1.end());
  auto end2 = std::unique(v2.begin(), v2.end());

  v1.erase(end1, v1.end());
  v2.erase(end2, v2.end());

  printDuplicates(v1, v2);

  return 0;
}
