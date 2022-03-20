#include <stack>
#include <iostream>
#include <memory>
#include <string>

int main(int argc, char** argv) {
  auto ps = std::make_shared<std::stack<int>>();
  auto n = std::stoi(argv[1]);

  while (n > 0) {
    ps->push(n % 2);
    n >>= 1;
  }

  while (!ps->empty()) {
    std::cout << ps->top();
    ps->pop();
  }
  std::cout << std::endl;

  return 0;
}
