#include <iostream>
#include <vector>
#include <algorithm>

void printSum(int num) {
    auto f = [&num](const int n) { return n + num; };
    std::cout << f(5) << std::endl;
}

int main() {
    printSum(5);
}
