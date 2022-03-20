#include <iostream>
#include <vector>

auto findNum(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end,
                                                   const int val) {
    for (; beg != end; ++beg) {
        if (*beg == val) {
            return beg;
        }
    }
    return end;
}

int main() {
    std::vector<int> v {1,2,3,4};
    auto result = findNum(v.cbegin(), v.cend(), 5);
    std::cout << *result << std::endl;
}
