#include <stack>
#include <iostream>
#include <memory>
#include <string>

// infix: (A+B)*C-(D-E)*(F+G)
// fully parethesized: (((A+B)*C)-((D-E)*(F+G)))
// postfix: AB+C*DE-FG+*-
// prefix: -*+ABC*-DE+FG
std::string getPostfix(const std::string& expr) {
  std::stack<char> stk;
  std::string ret;
  /* check the expr has valid parentheses */
  for (const auto& c : expr) {
    switch (c) {
    case '+':
    case '-':
      while (!stk.empty() && stk.top() != '(') {
        ret += stk.top();
        stk.pop();
      }
      stk.push(c);
      break;
    case '*':
    case '/':
      while (!stk.empty() && (stk.top() != '+'
             && stk.top() != '-' && stk.top() != '(')) {
        ret += stk.top();
        stk.pop();
      }
      stk.push(c);
      break;
    case '(':
      stk.push(c);
      break;
    case ')':
      while (!stk.empty() && stk.top() != '(') {
        ret += stk.top();
        stk.pop();
      }
      stk.pop();
      break;
    default:
      ret += c;
      break;
    } // end switch
  }

  while (!stk.empty()) {
    ret += stk.top();
    stk.pop();
  }

  return ret;
}

int main() {
  std::string intput = "(1+2)*3-(4-5)*(6+7)";
  std::cout << getPostfix(intput) << std::endl;

  return 0;
}
