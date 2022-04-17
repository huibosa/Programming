#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <numeric>

int main() {
    std::vector<double> dvec{1.0, 5.5, 7.4};

    auto val = std::accumulate(dvec.cbegin(), dvec.cend(), 0.0);

    std::cout << val << std::endl;
}
