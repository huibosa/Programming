#include <stack>
#include <string>
#include <iostream>
#include <memory>
#include <vector>

int main() {
  auto pExprStack = std::make_shared<std::stack<std::string>>();
  auto pOprStack = std::make_shared<std::stack<std::string>>();

  std::string raw = "1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )";
  std::vector<std::string> text;
  std::string numbers = "1234567890";
  std::string oprs = "+-*/";

  for (const auto& c : raw) {
    if (c != ' ') {
      text.push_back(std::string(1, c));
    }
  }
  // assumed that the input is valid
  for (const auto& s : text) {
    if (s.find_first_of(numbers) != std::string::npos) {
      pExprStack->push(s);
    }
    else if (s.find_first_of(oprs) != std::string::npos) {
      pOprStack->push(s);
    }
    else if (s == ")") {
      auto op = pOprStack->top();
      pOprStack->pop();

      auto v1 = pExprStack->top();
      pExprStack->pop();
      auto v2 = pExprStack->top();
      pExprStack->pop();

      auto newExpr = "( " + v2 + " " + op + " " + v1 + " " + ")";
      pExprStack->push(newExpr);
    }
  }

  for (; !pExprStack->empty(); pExprStack->pop()) {
    std::cout << pExprStack->top();
  }
  std::cout << std::endl;

  return 0;
}
