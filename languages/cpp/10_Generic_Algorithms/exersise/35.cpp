#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v {1,2,3,4,6};

    for (auto it = std::prev(v.cend()); true; --it) {
        std::cout << *it << " ";
        if (it == v.cbegin()) {
            break;
        }
    }
    std::cout << std::endl;
}
