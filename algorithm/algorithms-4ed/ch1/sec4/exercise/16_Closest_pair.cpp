#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cfloat> // DBL_MAX;
#include <limits> // numeric_limits<double>::max()
#include <random>

std::pair<double, double> closestPair1(const std::vector<double> &vals) {
  std::unordered_map<double, std::pair<double, double>> hashMap;

  for (int i = 0; i < vals.size(); ++i) {
    for (int j = i + 1; j < vals.size(); ++j) {
      hashMap[std::abs(vals[i] - vals[j])] = std::make_pair(vals[i], vals[j]);
    }
  }

  std::vector<double> temp;
  for (const auto& item : hashMap) {
    temp.push_back(item.first);
  }

  std::sort(temp.begin(), temp.end());

  return hashMap[temp.front()];
}

std::pair<double, double> closestPair2(std::vector<double> &vals) {
  std::sort(vals.begin(), vals.end());
  std::pair<double, double> retval;
  auto min = std::numeric_limits<double>::max();

  for (int i = 0; i < vals.size(); ++i) {
    auto diff = std::abs(vals[i] - vals[i+1]);
    if (diff < min) {
      min = diff;
      retval.first = vals[i];
      retval.second = vals[i+1];
    }
  }
  return retval;
}

int main() {
  std::vector<double> vec;

  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<double> distr(1, 100);

  for (int i = 0; i < 3000000; ++i) {
    vec.push_back(distr(generator));
  }

  std::sort(vec.begin(), vec.end());
  auto pivot = std::unique(vec.begin(), vec.end());
  vec.erase(pivot, vec.end());
  auto rng = std::default_random_engine {};
  std::shuffle(vec.begin(), vec.end(), rng);

  auto res = closestPair1(vec);
  printf("%f and %f\n", res.first, res.second);

  return 0;
}
