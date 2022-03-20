// Write a static method lg() that takes an int value N as argument and returns
// the largest int not larger than the base-2 logarithm of N. Do not use Math
//
// just think about a binary search, which has time complexity O(lgn)

#include <cmath>
#include <iostream>

auto lg(int val) {
    // 2^{lg\ n}=n
    // 1=n/2^{lg\ n}
    int ret = 0;
    for (int n = val; n > 1; n >>= 1) {
        ++ret;
    }
    return ret;
}

int main() {
    std::cout << lg(7) << std::endl;
}
