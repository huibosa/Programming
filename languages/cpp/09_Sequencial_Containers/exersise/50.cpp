#include <iostream>
#include <vector>
#include <string>

int sumVector(const std::vector<std::string>& v) {
    int retval = 0;

    for (const auto& s : v) {
        retval += std::stoi(s);
    }

    return retval;
}

int main() {
    std::vector<std::string> svec{ "1","2","3","4","5","6","7","8","9" };
    std::cout << sumVector(svec) << std::endl;
}
