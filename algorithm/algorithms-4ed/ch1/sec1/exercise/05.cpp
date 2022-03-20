/* 1.1.5 Write a code fragment that prints true if the double variables x and y */
/* are both strictly between 0 and 1 and false otherwise. */

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  double x = std::stod(argv[1]);
  double y = std::stod(argv[2]);

  if ((0 < x && x < 1) && (0 < x && y < 1) ) {
    std::cout << "true" << "\n";
  } else {
    std::cout << "false" << "\n";
  }

  return 0;
}
