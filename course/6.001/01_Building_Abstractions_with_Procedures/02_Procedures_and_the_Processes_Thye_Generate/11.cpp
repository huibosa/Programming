#include <iostream>

int fooIter(int a, int b, int c, int count) {
  if (count < 0) {
    return a;
  }

  return fooIter((a + 2 * b + 3 * c), a, b, --count);
}

int main() {
  std::cout << fooIter(0, 1, 2, 5) << "\n";
  
  return 0;
}
