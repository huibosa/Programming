/* Exercise 9.27: Write a program to find and remove the odd-valued */
/* elements in a forward_list<int>. */

#include <iostream>
#include <forward_list>
#include <algorithm>

void removeOdd1(std::forward_list<int>& flst) {
  for (auto prev = flst.before_begin(), cur = flst.begin() ; cur != flst.end(); ) {
    if (*cur & 0x01) {
      cur = flst.erase_after(prev);
    } else {
      ++prev;
      ++cur;
    }
  }
}

void removeOdd2(std::forward_list<int>& flst) {
  auto pivot = std::remove_if(flst.begin(), flst.end(), [](int i) { return i & 0x01; });
  flst.erase_after(pivot, flst.end());
}

int main() {
  std::forward_list<int> flst{0,1,2,3,4,5,6,7,8,9};

  removeOdd1(flst);
    
  for (const auto& ix : flst) {
    std::cout << ix << " ";
  }
  std::cout << std::endl;
}
