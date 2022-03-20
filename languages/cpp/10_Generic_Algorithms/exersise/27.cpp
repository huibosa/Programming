#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec{0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
    std::list<int> lst;

    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));

    std::for_each(lst.begin(), lst.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
}
