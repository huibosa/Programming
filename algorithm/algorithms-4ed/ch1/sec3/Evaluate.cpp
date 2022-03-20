#include <cmath>
#include <iostream>
#include <memory>
#include <stack>
#include <string>

int main() {
  auto ops = std::make_shared<std::stack<std::string>>();
  auto vals = std::make_shared<std::stack<double>>();

  std::string expr;
  std::cin >> expr;

  for (auto iter = expr.cbegin(); iter != expr.cend(); ++iter) {
    if (*iter == '(') {
      continue;
    } else if (*iter == '+') {
      ops->push(std::string(1, *iter));
    } else if (*iter == '-') {
      ops->push(std::string(1, *iter));
    } else if (*iter == '*') {
      ops->push(std::string(1, *iter));
    } else if (*iter == '/') {
      ops->push(std::string(1, *iter));
    } else if (*iter == 's' && std::string(iter + 1, iter + 3) == "qrt") {
      ops->push("sqrt");
      iter + 3;
    } else if (*iter == ')') {
      auto op = ops->top();
      ops->pop();
      auto v1 = vals->top();
      vals->pop();

      if (op == "+") {
        auto v2 = vals->top();
        vals->pop();
        v1 += v2;
      } else if (op == "-") {
        auto v2 = vals->top();
        vals->pop();
        v1 -= v2;
      } else if (op == "*") {
        auto v2 = vals->top();
        vals->pop();
        v1 *= v2;
      } else if (op == "/") {
        auto v2 = vals->top();
        vals->pop();
        v1 /= v2;
      } else if (op == "sqrt") {
        v1 = std::sqrt(v1);
      }
      vals->push(v1);
    } else {
      vals->push(std::stod(std::string(1, *iter)));
    }
  }

  auto result = vals->top();
  std::cout << result << std::endl;

  return 0;
}
