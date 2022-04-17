#include <algorithm>
#include <array>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <stack>

int main() {
    std::stack<int> intStack;

    for (size_t ix = 0; ix != 0; ++ix) {
        intStack.push(ix);
    }
    while (!intStack.empty()) {
        auto value = intStack.top();
        intStack.pop();
    }
}
