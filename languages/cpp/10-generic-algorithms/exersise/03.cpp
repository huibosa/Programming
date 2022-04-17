#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> ivec;

    for (size_t ix = 0; ix != 100; ++ix) {
        ivec.push_back(ix);
    }

    auto val = std::accumulate(ivec.cbegin(), ivec.cend(), 100);

    std::cout << val << std::endl;
}
