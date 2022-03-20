#include <iostream>

int main() {
    int ix = 7;

    auto check_and_decrement = [&ix]() {return ix > 0 ? --ix : ix;};

    while (check_and_decrement()) {
        std::cout << ix << " ";
    }
    std::cout << std::endl;

    std::cout << "value of ix:" << ix << std::endl;
}
