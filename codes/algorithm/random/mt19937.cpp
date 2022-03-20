#include <iostream>
#include <random>

int main() {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  /* std::uniform_int_distribution<int> distr(-1000, 1000); */
  std::uniform_real_distribution<double> distr(-1, 1);

  std::cout << distr(generator) << "\n";

  return 0;
}
