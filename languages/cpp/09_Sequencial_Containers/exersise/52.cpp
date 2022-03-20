#include <stack>
#include <string>
#include <iostream>
#include <system_error>

int main() {
    std::stack<char> stk;
    std::string expression{"This is (pezy)"};
    bool expr_start = false;

    for (const auto& c : expression) {
        if (c == '(') { expr_start = true; continue; }
        else if (c == ')') { expr_start = false; }

        if (expr_start) { stk.push(c); }
    }

    std::string repstr;
    while (!stk.empty()) {
        repstr += stk.top();
        stk.pop();
    }

    expression.replace(expression.find('(') + 1, repstr.size(), repstr);
    std::cout << expression << std::endl;
}
