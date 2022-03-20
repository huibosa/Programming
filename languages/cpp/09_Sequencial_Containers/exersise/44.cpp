#include <cstddef>
#include <iostream>
#include <string>

auto replaceAll(std::string& s, const std::string& oldVal, const std::string& newVal) {
    for (size_t pos = 0; pos < s.size();) {
        if (s[pos] == oldVal[0] && s.substr(pos, pos + oldVal.size()) == oldVal) {
            s.replace(pos, pos + oldVal.size(), newVal);
            pos += newVal.size();
        }
        else {
            ++pos;
        }
    }
}

int main() {
    std::string s = "thruandthru";
    replaceAll(s, "thru", "through");

    std::cout << s << std::endl;
}
