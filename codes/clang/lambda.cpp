#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1,2,3,4,5};

  auto mid = [&] { return vec.begin() + vec.size() / 2; };

  for (int i = 6; i < 10; ++i) {
    vec.push_back(i);
    std::cout << *mid() << "\n";
  }

  return 0;
}
