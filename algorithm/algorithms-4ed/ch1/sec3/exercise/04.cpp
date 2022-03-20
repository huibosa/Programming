#include <iostream>
#include <memory>
#include <stack>
#include <string>

bool checkParentheses(const std::string& text) {
  auto ops = std::make_shared<std::stack<char>>();

  for (const auto &c : text) {
    if (c == '(' || c == '[' || c == '{'){
      ops->push(c);
    } else if ((c == ')' && ops->top() == '(')
            || (c == ']' && ops->top() == '[')
            || (c == '}' && ops->top() == '{')) {
      ops->pop();
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  auto validity = checkParentheses("[()]{}{[()()]()}");

  std::cout << (validity ? "true" : "false") << std::endl;

  return 0;
}
