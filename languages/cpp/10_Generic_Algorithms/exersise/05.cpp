#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <vector>
#include <numeric>

int main() {
    std::list<const char*> roster1{"hello"};
    std::list<const char*> roster2{"hello"};

    auto state = std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

    std::cout << (state ? "yes" : "no") << std::endl;
}
