/* Write a code fragment to print the transposition (rows and columns changed) */
/* of a two-dimensional array with M rows and N columns. */

#include <cstdio>
#include <iostream>
#include <vector>
#include <array>

int main() {
    int A[2][3] { {1,2,3}, {4,5,6} };
    int T[3][2];

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 2; ++col) {
            T[row][col] = A[col][row];
        }
    }

    for (const auto& inner : T) {
        for (const auto& i : inner) {
            std::cout << i << "   ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
