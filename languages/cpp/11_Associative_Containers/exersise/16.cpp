#include <iostream>
#include <map>

int main() {
    std::map<int, int> table = {{0,4}, {1,7}};

    auto iter = table.find(0);
    iter->second = 7;

    for (auto beg = table.cbegin(); beg != table.cend(); ++beg) {
        std::cout << beg->first << ":" << beg->second << std::endl;
    }
}
