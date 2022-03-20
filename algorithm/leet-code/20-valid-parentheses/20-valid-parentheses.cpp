#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stk;

    for (const auto &ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        stk.push(ch);
      } else if (!stk.empty() && (ch == ')' || ch == ']' || ch == '}')) {
        if ((ch == ')' && stk.top() == '(') ||
            (ch == ']' && stk.top() == '[') ||
            (ch == '}' && stk.top() == '{')) {
          stk.pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }

    if (stk.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution sln;
  if (sln.isValid("]")) {
    std::cout << "true" << std::endl;
  }
}
