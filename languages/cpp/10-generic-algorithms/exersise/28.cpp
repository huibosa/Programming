#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <array>

void showreuslt(const std::list<int>& lst) {
    std::for_each(lst.begin(), lst.end(), [](const int i) {std::cout << i << " ";});
    std::cout << std::endl;
}

int main() {
    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    std::list<int> lst1;
    std::list<int> lst2;
    std::list<int> lst3;

    std::copy(v.begin(), v.end(), std::back_inserter(lst1));
    showreuslt(lst1);

    std::copy(v.begin(), v.end(), std::front_inserter(lst2));
    showreuslt(lst2);

    auto iter = ++lst3.begin();
    std::copy(v.begin(), v.end(), std::inserter(lst3, iter));
    showreuslt(lst3);
}
