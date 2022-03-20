#include <cstdlib>
#include <iostream>

void hanoi(int n, char from, char to, char spare) {
  if (n == 1) {
    std::cout << "move the ring " << n << " from "
              << from << " to " << to << " via " << spare
              <<  "\n";
  } else {
    hanoi(n - 1, from, spare, to);
    std::cout << "move the ring " << n << " from "
              << from << " to " << to << " via " << spare
              << "\n";
    hanoi(n - 1, spare, to, from);
  }
}

int main() {
  hanoi(64, 'A', 'C', 'B');

  return 0;
}
