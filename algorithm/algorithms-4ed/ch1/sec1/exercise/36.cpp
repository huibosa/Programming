/*
1.1.36 Empirical shuffle check. Run computational experiments to check that our
shuffling code on page 32 works as advertised. Write a program ShuffleTest that
takes command-line arguments M and N, does N shuffles of an array of size M
that is initial- ized with a[i] = i before each shuffle, and prints an M-by-M
table such that row i gives the number of times i wound up in position j for
all j. All entries in the array should be close to N/M.
*/

#include <iostream>
#include <string>

void shuffle(double a[], int n) {
  for (int ix = 0; ix < n; ++ix) {
    auto random = rand() % n;

    auto temp = a[ix];
    a[ix] = a[random];
    a[random] = temp;
  }
}

int main(int argc, char** argv) {
  auto size = std::stoi(argv[1]);
  auto times = std::stoi(argv[2]);
  auto pa = new double[size]();

  for (int ix = 0; ix < size; ++ix) {
    pa[ix] = ix;
  }

  for (int ix = 0; ix < times; ++ix) {
    shuffle(pa, size);
  }
}
