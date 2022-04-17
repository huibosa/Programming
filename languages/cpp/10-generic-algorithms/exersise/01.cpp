#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> ivec{1,2,3,5,1,5,7,3,7,9,3,5,8,5,3};

    for (size_t ix = 0; ix != 10; ++ix) {
        ivec.push_back(ix);
    }

    auto cnt = std::count(ivec.cbegin(), ivec.cend(), 5);

    std::cout << cnt << std::endl;
}
