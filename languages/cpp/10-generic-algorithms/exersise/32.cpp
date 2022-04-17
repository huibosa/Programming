#include "Sales_item.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<Sales_item> vec;
    std::istream_iterator<Sales_item> in_iter(std::cin);
    std::istream_iterator<Sales_item> eof;
    std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");

    while (in_iter != eof) {
        vec.push_back(*in_iter++);
    }

    std::sort(vec.begin(), vec.end(), compareIsbn);

}
