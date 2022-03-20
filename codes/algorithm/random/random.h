#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>

class Random {
public:
  double randUniform(double min, double max);
  int rangeRandom(int min, int max);
  int rangeRandom2(int min, int max);
  int rangeRandom3(int min, int max);
private:
};

inline double Random::randUniform(double min, double max) {
  auto ret = rand() / static_cast<double>(RAND_MAX) * (max - min) + min;
  return ret;
}

// unbiased cpp way
inline int Random::rangeRandom(int min, int max) {
  std::random_device rand_dev;
  std::mt19937 rng(rand_dev());
  std::uniform_int_distribution<int> gen(min, max);

  return gen(rng);
}

// unbiased way
inline int Random::rangeRandom2(int min, int max) {
  int n = max - min + 1;
  int remainder = RAND_MAX % n;
  int x;
  
  do{
      x = rand();
  }while (x >= RAND_MAX - remainder);
  
  return min + x % n;
}

// biased way, toward lower end
inline int Random::rangeRandom3(int min, int max) {
  return rand() % (max - min + 1) + min;
}
