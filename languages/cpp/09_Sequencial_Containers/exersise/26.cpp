/* Exercise 9.26: Using the following definition of ia, copy ia into a vector */
/* and into a list. Use the single-iterator form of erase to remove the */
/* elements with odd values from your list and the even values from your */
/* vector. */

// int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> odd;
  std::list<int> even;

  odd.assign(std::begin(ia), std::end(ia));
  even.assign(std::begin(ia), std::end(ia));

  for (auto iter = odd.begin(); iter != odd.end();) {
    if (!(*iter & 0x01)) {
      iter = odd.erase(iter);
    } else {
      ++iter;
    }
  }

  for (auto iter = even.begin(); iter != even.end();) {
    if (*iter & 0x01) {
      iter = even.erase(iter);
    } else {
      ++iter;
    }
  }

  for (const auto &i : odd) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for (const auto &i : even) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
