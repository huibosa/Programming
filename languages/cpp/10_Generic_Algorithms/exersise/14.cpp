#include <iostream>

int main() {
    auto f = [](int a, int b) {return a + b;};

    std::cout << f(1,2) << std::endl;
}
