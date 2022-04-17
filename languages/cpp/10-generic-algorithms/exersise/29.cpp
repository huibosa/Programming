#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>

int main() {
    std::ifstream ifstrm("strings");
    std::istream_iterator<std::string> in_iter(ifstrm);
    std::istream_iterator<std::string> eof;
    std::vector<std::string> svec(in_iter, eof);

    std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<std::string>(std::cout, " "));
}
