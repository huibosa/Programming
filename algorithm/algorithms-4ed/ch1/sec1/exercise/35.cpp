#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Dice {
public:
  Dice() = default;

public:
  auto getExact() const;
  auto getExperim(int n) const;
  auto throwDice() const;

public:
  const int SIDES = 6;
};

inline auto Dice::getExact() const {
  auto dist = new double[2*SIDES]();

  for (int ix = 1; ix < SIDES; ++ix) {
    for (int iv = 1; iv < SIDES; ++iv) {
      dist[ix+iv] += 1.0;
    }
  }

  for (int ix = 2; ix < sizeof(dist); ++ix) {
    dist[ix] /= (SIDES * SIDES);
  }

  return dist;
}

inline auto Dice::throwDice() const {
  return (rand() % SIDES) + (rand() % SIDES);
}

inline auto Dice::getExperim(int n) const {
  auto dist = new double[2*SIDES+1]();

  for (int i = 0; i < n; ++i) {
    dist[throwDice()]++;
  }

  for (int ix = 2; ix <= 2*SIDES; ++ix) {
    dist[ix] /= n;
  }
  return dist;
}

int main(int argc, char** argv) {
  auto n = std::stoi(argv[1]);

  Dice dice;

  for (int ix = 2; ix < 2*dice.SIDES; ++ix) {
    printf("%7d", ix);
  }
  std::cout << std::endl;

  auto exact = dice.getExact();
  for (int ix = 2; ix < 2*dice.SIDES; ++ix) {
    printf("%7.3f", exact[ix]);
  }
  std::cout << std::endl;

  for (int ix = 2; ix < 2*dice.SIDES; ++ix) {
    printf("%7d", ix);
  }
  std::cout << std::endl;


  auto experim = dice.getExperim(n);
  for (int ix = 2; ix < 2*dice.SIDES; ++ix) {
    printf("%7.3f", experim[ix]);
  }
  std::cout << std::endl;
}
