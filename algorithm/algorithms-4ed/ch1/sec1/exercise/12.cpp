// What does the following code fragment print

#include <iostream>
#include <vector>

int main() {
  int a[10];

  for (int i = 0; i < 10; ++i) {
    a[i] = 9 - i;
  }
  for (int i = 0; i < 10; ++i) {
    a[i] = a[a[i]];
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << i << "\n";
  }   // 0 1 2 3 4 5 6 7 8 9

  return 0;
}
