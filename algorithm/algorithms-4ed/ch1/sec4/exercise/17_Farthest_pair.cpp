#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cfloat> // DBL_MAX;
#include <limits> // numeric_limits<double>::max()
#include <random>

std::pair<double, double> closestPair2(std::vector<double> &vals) {
  std::sort(vals.begin(), vals.end());
  std::pair<double, double> retval;
  auto max = std::numeric_limits<double>::min();

  for (int i = 0; i < vals.size(); ++i) {
    auto diff = std::abs(vals[i] - vals[i+1]);
    if (diff > max) {
      max = diff;
      retval.first = vals[i];
      retval.second = vals[i+1];
    }
  }
  return retval;
}

int main() {
  std::vector<double> vec{1,5,7,2,5,8,8,32,6,73,6,8,8,3,47,4,753,3,4,7,3,37};

  srand(time(0));
  for (int i = 0; i < 10000; ++i) {
    vec.push_back(rand() % 100);
  }

  auto res = closestPair2(vec);
  printf("%f and %f\n", res.first, res.second);

  return 0;
}
