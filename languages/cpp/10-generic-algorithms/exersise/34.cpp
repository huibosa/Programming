#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v {1,2,3,4,6};

    std::for_each(v.crbegin(), v.crend(), [](const int& i) {std::cout << i << " ";});
    std::cout << std::endl;
}
