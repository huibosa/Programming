#include <iostream>
#include <algorithm>
#include <vector>

class Test {
public:
  Test(int s): sz(s) {}
  bool operator()(const int& a) { return a > sz; }
private:
  int sz;
};

int main() {
  std::vector<int> vec{1,2,3,4,5};
  auto sz = 3;
  /* auto res = std::find_if(vec.begin(), vec.end(), [sz](const auto& n) { return n >= sz; }); */
  auto res = std::find_if(vec.begin(), vec.end(), Test(sz));

  std::cout << *res << "\n";

  return 0;
}
