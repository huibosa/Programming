#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{1,2,3};

    std::cout << (v1 == v2 ? "equal" : "not equal") << std::endl;
}
