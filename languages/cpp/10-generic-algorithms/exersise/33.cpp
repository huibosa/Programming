#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main() {
    std::ifstream ifstrm("input");
    std::istream_iterator<int> in_iter(ifstrm);
    std::istream_iterator<int> eof;

    std::ofstream ofstrm1("odd");
    std::ofstream ofstrm2("even");
    std::ostream_iterator<int> out_iter1(ofstrm1, "\n");
    std::ostream_iterator<int> out_iter2(ofstrm2, "\n");

    std::vector<int> v(in_iter, eof);

    auto pivot = std::partition(v.begin(), v.end(), [](const int& i) {return i & 0x01;});
    std::copy(v.begin(), pivot, out_iter1);
    std::copy(pivot, v.end(), out_iter2);
}
