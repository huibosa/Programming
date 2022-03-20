/* 1.1.23 Add to the BinarySearch test client the ability to respond to a second argu- */
/* ment: + to print numbers from standard input that are not in the whitelist, - to print */
/* numbers that are in the whitelist. */

#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using Index = int;

Index rank(int key, std::vector<int> &a, Index head, Index tail) {
  if (head > tail) {
    return -1;
  }

  auto mid = head + (tail - head) / 2;
  if (key < a[mid]) {
    return rank(key, a, head, mid - 1);
  } else if (key > a[mid]) {
    return rank(key, a, mid + 1, tail);
  } else {
    return mid;
  }
}

Index rank(int key, std::vector<int> &a) { return rank(key, a, 0, a.size()); }

int main(int argc, char **argv) {
  std::vector<int> whiteList{2,4,6,8};

  int val;

  if (strcmp(argv[1], "+")) {
    while (std::cin >> val) {
      if (rank(val, whiteList) != -1) {
        std::cout << val << std::endl;
      }
    }
  } else if (strcmp(argv[1], "-")) {
    while (std::cin >> val) {
      if (rank(val, whiteList) == -1) {
        std::cout << val << std::endl;
      }
    }
  }
}
