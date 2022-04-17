#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

int main() {
    std::istream_iterator<int> in_iter(std::cin);
    std::istream_iterator<int> eof;
    std::vector<int> ivec(in_iter, eof);

    std::cout << "Output: " << std::endl;
    std::sort(ivec.begin(), ivec.end());
    std::unique_copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(std::cout, "\n"));
}
