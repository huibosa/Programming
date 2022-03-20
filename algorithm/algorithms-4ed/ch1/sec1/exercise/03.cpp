/* 1.1.3 Write a program that takes three integer command-line arguments and */
/* prints equal if all three are equal, and not equal otherwise. */

#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char** argv) {
  if (argc != 4) {
    throw std::runtime_error("wrong argument number\n");
  }

  auto num1 = std::stoi(argv[1]);
  auto num2 = std::stoi(argv[2]);
  auto num3 = std::stoi(argv[3]);

  std::cout << (num1 == num2 && num2 == num3 ? "equal" : "not equal") << "\n";

  return 0;
}
