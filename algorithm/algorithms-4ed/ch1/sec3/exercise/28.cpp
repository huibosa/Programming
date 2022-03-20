#include <ctime>
#include <iostream>
#include <list>
#include <vector>
#include <string>

int find_max(const std::list<int> &lst) {
  if (++lst.begin() == lst.end()) {
    return *lst.begin();
  } else {
    auto temp = find_max(std::list<int>(++lst.begin(), lst.end()));
    return (*lst.begin() > temp ? *lst.begin() : temp);
  }
}

int main() {
  std::list<int> lst{5,23,44,29,7,6};

  std::cout << find_max(lst) << std::endl;

  return 0;
}
