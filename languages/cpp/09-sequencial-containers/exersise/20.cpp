#include <iostream>
#include <deque>
#include <list>

int main() {
    std::list<int> lst{0,1,2,3,4,5,6,7,8,9};
    std::deque<int> odd;
    std::deque<int> even;

    for (const auto& i : lst) {
        if (i & 0x01) {
            odd.push_back(i);
        }
        else {
            even.push_back(i);
        }
    }

    for (const auto& i : odd) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (const auto& i : even) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
