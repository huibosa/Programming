#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> lst{1,2,3,4,5};
    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{1,2,3,4};

    std::cout << (std::vector<int>(lst.cbegin(), lst.cend()) == vec1 ?  "true" : "false")
              << std::endl;

    std::cout << (std::vector<int>(lst.cbegin(), lst.cend()) == vec2 ?  "true" : "false")
              << std::endl;
}
