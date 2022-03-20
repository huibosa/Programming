#include <iostream>
#include <string>

void modifyName(std::string& name, const std::string& prefix, const std::string& suffix) {
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    name.append(suffix.cbegin(), suffix.cend());
}

int main() {
    std::string name{"huibosa"};

    modifyName(name, "Mr. ", " Jr");
    std::cout << name << std::endl;
}
