#include <iostream>
#include <string>
#include <string.h>

int main() {
    std::cout << "How long do you want the string? ";
    std::size_t size = 0;
    std::cin >> size;
    std::cin.ignore();
    auto* input = new char[size + 1]();
    std::cout << "Enter a string";
    std::cin.get(input, size + 1);
    std::cout << input << std::endl;
    delete [] input;
}
