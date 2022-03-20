#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

void print(std::vector<std::string> v) {
    for (const auto& s : v) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

void print(std::multiset<std::string> c) {
    for (const auto& s : c) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> v{"aa", "bb", "cc"};
    std::multiset<std::string> c{{"dd", "ee"}, {"ff", "gg"}};
    // std::copy(v.cbegin(), v.cend(), std::inserter(c, c.end()));
    // std::copy(v.cbegin(), v.cend(), std::back_inserter(c));
    // std::copy(c.cbegin(), c.cend(), std::inserter(v, v.end()));
    std::copy(c.cbegin(), c.cend(), std::back_inserter(v));
    print(c);
}
