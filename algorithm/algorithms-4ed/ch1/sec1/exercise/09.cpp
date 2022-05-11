/* Write a code fragment that puts the binary representation of a positive */
/* integer N into a String s. Solution: Java has a built-in method */
/* Integer.toBinaryString(N) for this job, but the point of the exercise is to see */
/* how such a method might be implemented. Here is a particularly concise */
/* solution: */

#include <iostream>
#include <string>

std::string intToBinary(int num) {
    std::string ret;

    for (; num != 0; num >>= 1) {
        ret = std::to_string(num % 2) + ret;
    }
    return ret;
}

int main() {
    std::cout << intToBinary(55) << std::endl;
}
