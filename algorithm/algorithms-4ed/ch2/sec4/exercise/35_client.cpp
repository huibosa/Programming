#include "35_Sampling_from_a_discret_probability_distribution.h"
#include <unordered_map>
#include <vector>

int main() {
  std::vector<double> weights{5, 1, 3, 4, 2, 20};
  Sample sampling(weights);
  sampling.changeKey(5, 5);

  std::unordered_map<int, int> res;
  for (int i = 0; i < 20000; ++i) {
    auto index = sampling.random();
    if (res.find(index) != res.end()) {
      res[index]++;
    } else {
      return res[index] = 0;
    }
  }

  for (const auto &p : res) {
    printf("Key = %d, (value = %lf) count = %d\n", p.first, weights[p.first],
           p.second);
  }

  return 0;
}
