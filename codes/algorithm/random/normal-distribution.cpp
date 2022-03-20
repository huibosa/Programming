#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <map>

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::normal_distribution<> d(5,2);

  std::map<int, int> hist;

  for (int n = 0; n < 10000; ++n) {
    ++hist[std::round(d(gen))];
  }

  for (const auto& p : hist) {
    std::cout << std::setw(2)
              << p.first << std::string(p.second/20, '*') << '\n';
  }

  return 0;
}
