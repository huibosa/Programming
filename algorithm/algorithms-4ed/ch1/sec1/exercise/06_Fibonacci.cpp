/* What does the following program print? */

#include <iostream>

int main() {
  int f = 0;
  int g = 1;

  for (int i = 0; i < 15; ++i) {
    std::cout << f << "\n";
    f = f + g;
    g = f - g;
  }

  return 0;
}
