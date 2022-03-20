#include <iostream>
#include <stack>
#include <memory>

int main() {
  auto stk = std::make_shared<std::stack<int>>();
  int temp;
  
  while (std::cin >> temp) {
    stk->push(temp);
  }

  while (!stk->empty()) {
    std::cout << stk->top() << std::endl;
    stk->pop();
  }

  return 0;
}
