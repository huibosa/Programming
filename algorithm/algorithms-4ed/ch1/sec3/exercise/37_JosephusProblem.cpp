#include <iostream>
#include <iterator>
#include <memory>
#include <list>
#include <string>

int josephus(int n, int k) {
  if (n == 1) {
    return 0;
  } else {
    return (josephus(n - 1, k) + k) % n;
  }
}

int main(int argc, char** argv) {
  auto n = std::stoi(argv[1]);
  auto k = std::stoi(argv[2]);

  std::cout << "The survivor will be " << josephus(n, k)
            << std::endl;

  return 0;
}
