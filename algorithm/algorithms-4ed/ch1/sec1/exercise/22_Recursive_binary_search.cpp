/* 1.1.22 Write a version of BinarySearch that uses the recursive rank() given on page */
/* 25 and traces the method calls. Each time the recursive method is called, print the argu- */
/* ment values lo and hi, indented by the depth of the recursion. Hint: Add an argument */
/* to the recursive method that keeps track of the depth. */

#include <iostream>
#include <vector>

using Index = int;
int depth = 0;

Index rank(int key, std::vector<int> &a, Index head, Index tail) {
  std::cout << "Depth " << depth << ": "
            << "head = " << head << "\t|\t"
            << "tail = " << tail << std::endl;
  depth++;

  if (head > tail) {
    return -1;
  }

  auto mid = head + (tail - head) / 2;
  if (key < a[mid]) {
    return rank(key, a, head, mid-1);
  } else if (key > a[mid]) {
    return rank(key, a, mid+1, tail);
  } else {
    return mid;
  }
}

Index rank(int key, std::vector<int> &a) {
  return rank(key, a, 0, a.size());
}

int main() {
  std::vector<int> a;
  for (int i = 0; i < 1000; i++) {
    a.push_back(i);
  }

  std::cout << rank(777, a) << std::endl;
}
