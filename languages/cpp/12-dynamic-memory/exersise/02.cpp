#include <iostream>
#include "2.h"

int main() {
    const StrBlob csb{"a", "b", "c"};
    StrBlob sb{"aa", "bb", "cc"};

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "ee";
    std::cout << sb.front() << " " << sb.back() << std::endl;
}
