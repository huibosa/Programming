#include <iostream>
#include <vector>

bool findNum(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end,
                                                   const int val) {
    for (auto iter = beg; iter != end; ++iter) {
        if (*iter == val) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> v {1,2,3,4};
    auto flag = findNum(v.cbegin(), v.cend(), 4);
    std::cout << (flag ? "yes" : "no") << std::endl;
}
