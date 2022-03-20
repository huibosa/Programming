#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <vector>
#include <numeric>

int main() {
    std::list<int> vals;

    std::fill_n(std::back_inserter(vals), 10, 5);

    for (const auto& ix : vals) {
        std::cout << ix << " ";
    }
    std::cout << std::endl;
}
