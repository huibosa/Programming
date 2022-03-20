#include <iostream>
#include <string>

auto replaceAll(std::string& s, const std::string& oldVal, const std::string& newVal) {
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        if (std::string(iter, iter + oldVal.size()) == oldVal) {
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.begin(), newVal.end());
        }
    }
}

int main() {
    std::string s = "thruandthru";
    replaceAll(s, "thru", "through");

    std::cout << s << std::endl;
}
