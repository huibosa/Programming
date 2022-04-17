#include <iostream>

template<typename data>
bool compare(data left, data right) {
    return left > right;
}

template<>
bool compare(std::string left, std::string right) {
    return left.length() > right.length();
}
