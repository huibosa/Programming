// Write and test your own versions of the compare functions

#include <iostream>
#include <vector>

template<typename _Tp>
int compare(const _Tp& lhs, const _Tp& rhs) {
  if (lhs < rhs) { return -1; }
  if (rhs < lhs) { return 1; }
  return 0;
}

int main() {
  std::cout << compare(1, 0) << "\n";
  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{4, 5, 6};

  std::cout << compare(vec1, vec2) << "\n";

  return 0;
}
