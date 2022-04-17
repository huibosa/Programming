#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec;
//     std::list<int> lst;

//     int i;
//     while (std::cin >> i) {
//         lst.push_back(i);
//     }

//     std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));
    
    vec.reserve(10);
    std::fill_n(std::back_inserter(vec), 10, 0);

    for (const auto& ix : vec) {
        std::cout << ix << " ";
    }
    std::cout << std::endl;
}
