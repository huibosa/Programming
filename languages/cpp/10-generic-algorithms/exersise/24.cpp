#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

bool check_size(int n, const std::string& tar) {
    return n > tar.size();
}

int main() {
    std::vector<int> ivec{1,2,5,6,12,5,6,88,3,4};

    auto iter = std::find_if(ivec.begin(), ivec.end(),
                         std::bind(check_size, std::placeholders::_1, "congratulations"));

    std::cout << *iter << std::endl;
}
