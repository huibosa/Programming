#include <iostream>
#include <string>

void modifyName(std::string& name, const std::string& prefix, const std::string& suffix) {
    name.insert(0, prefix);
    name.insert(name.size(), suffix);
}

int main() {
    std::string name{"huibosa"};

    modifyName(name, "Mr. ", " Jr");
    std::cout << name << std::endl;
}
