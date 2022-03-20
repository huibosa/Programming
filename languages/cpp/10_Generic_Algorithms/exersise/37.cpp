#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>

int main() {
    std::vector<int> vec {0,1,2,3,4,5,6,7,8,9};
    std::list<int> lst;
    std::ostream_iterator<int> out_iter(std::cout);

    std::copy(vec.crbegin() + 2, vec.crbegin() + 8, std::back_inserter(lst));
    std::copy(lst.cbegin(), lst.cend(), out_iter);
}
