#include <vector>
#include <iostream>
#include <list>

int main() {
    std::list<int> ilst{1,2,3};
    std::vector<int> ivec{4,5,6};

    std::vector<double> dvec1(ilst.cbegin(), ilst.cend());
    std::vector<double> dvec2(ivec.cbegin(), ivec.cend());
}
