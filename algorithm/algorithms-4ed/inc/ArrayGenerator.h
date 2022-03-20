
#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <cstddef>
#include <cstdlib>
#include <random>
#include <sys/types.h>
#include <vector>

template <typename _Tp> class ArrayGenerator {
public:
  std::vector<_Tp> generateRandomArrayWith2Values(size_t, _Tp n1 = 0, _Tp n2 = 1);
  std::vector<_Tp> generateRandomArray(size_t, _Tp, _Tp);
};

template <typename _Tp>
std::vector<_Tp> ArrayGenerator<_Tp>::generateRandomArray(size_t n, _Tp min,
                                                             _Tp max) {
  std::vector<_Tp> ret;

  std::random_device rand_dev;
  std::mt19937 rng(rand_dev());
  std::uniform_real_distribution<_Tp> gen(min, max);

  for (size_t i = 0; i < n; ++i) {
    ret.push_back(gen(rng));
  }
  return ret;
}

// unbiased way
template <typename _Tp>
std::vector<_Tp> ArrayGenerator<_Tp>::generateRandomArrayWith2Values(size_t length,
                                                                     _Tp n1,
                                                                     _Tp n2) {
  std::random_device rand_dev;
  std::mt19937 rng(rand_dev());
  std::uniform_int_distribution<int> gen(0, 1);
  std::vector<_Tp> ret;

  for (size_t i = 0; i < length; ++i) {
    auto flag = gen(rng);
    if (flag == 0) {
      ret.push_back(n1);
    } else if (flag == 1) {
      ret.push_back(n2);
    }
  }

  return ret;
}

#endif /* ARRAYGENERATOR_H */
