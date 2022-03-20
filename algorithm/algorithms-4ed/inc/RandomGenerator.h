#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <cstddef>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

template <typename _Tp> class RandomGenerator {
public:
  RandomGenerator(ssize_t);
  std::shared_ptr<std::vector<_Tp>> getPointer() { return data; }
private:
  std::shared_ptr<std::vector<_Tp>> data;
};

template <typename _Tp>
inline RandomGenerator<_Tp>::RandomGenerator(ssize_t max)
        :data(std::make_shared<std::vector<int>>()) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<_Tp> distr(-max, max);

  for (int i = 0; i < max; ++i) {
    data->push_back(distr(generator));
  }
};

#endif /* RANDOMGENERATOR_H */
