#include <iostream>
#include <stack>
#include <string>

std::string evaluatePostfix(const std::string& expr) {
  std::stack<std::string> stk;
  
  for (const auto& ch : expr) {
    if (ch >= '0' && ch <= '9'){
      stk.push(std::string(1, ch));
      continue;
    }

    auto v1 = std::stoi(stk.top());
    stk.pop();
    auto v2 = std::stoi(stk.top());
    stk.pop();

    switch (ch) {
    case '+': stk.push(std::to_string(v2 + v1)); break;
    case '-': stk.push(std::to_string(v2 - v1)); break;
    case '*': stk.push(std::to_string(v2 * v1)); break;
    case '/': stk.push(std::to_string(v2 / v1)); break;
    }
  }

  return stk.top();
}

int main() {
  std::string temp;
  std::cin >> temp;

  auto result = evaluatePostfix(temp);
  result = evaluatePostfix("12+3*45-67+*-");
  std::cout << result << std::endl;

  return 0;
}
