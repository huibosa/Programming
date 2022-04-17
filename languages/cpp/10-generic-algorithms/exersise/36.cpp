#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>

int main() {
    std::list<int> values {1,4,6,36,7,4,0,33,6,8,0,45,1,57,};

    auto result = std::find(values.crbegin(), values.crend(), 0);
    
    std::cout << std::distance(result, values.crend()) << std::endl;
}
