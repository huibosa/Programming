#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cstdio>

std::vector<int> randomUniqueNum(int range, int outputCount) {
  std::vector<int> arr;
  for (int i = 0; i < range; ++i) {
    arr.push_back(i);
  }
  
  std::vector<int> ret;
  for (int i = 0; i < outputCount; ++i) {
    const auto random = rand() % (range - i) + 1;
    ret.push_back(arr[random]);
    arr[random] = arr[range - i];
  }

  return ret;
}

std::vector<int> randomUniqueNum2(int range, int outputCount) {
  std::unordered_set<int> set;
  while (set.size() < outputCount) {
    set.insert(rand() % range);
  }
  return {set.begin(), set.end()};
}

int main() {
  srand(time(0));
  char ch;
  
  while ((ch = getchar()) && ch != 'q'){
    while (getchar() != '\n') {
      continue;
    }
    auto res = randomUniqueNum(5, 5);

    for (const auto& i : res) {
      printf("%d ", i);
    }
  }
  
  return 0;
}
