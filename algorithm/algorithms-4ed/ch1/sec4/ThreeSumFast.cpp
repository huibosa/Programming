#include <cstddef>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>


std::size_t count(std::vector<int> nums) {
  int retval = 0;

  std::sort(nums.begin(), nums.end());

  for (auto i = nums.begin(); i != nums.end(); ++i) {
    for (auto j = i + 1; j != nums.end(); ++j) {
      if (std::binary_search(j + 1, nums.end(), -(*i)-(*j))) {
        retval++;
      }
    }
  }

  return retval;
}

double timeTrial(int N) {
  const std::size_t MAX = 1000000;
  std::vector<int> nums;

  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<std::size_t> distr(-MAX, MAX);

  nums.reserve(1000000);
  for (std::size_t i = 0; i < N; i++) {
    nums.push_back(distr(generator));
  }

  auto t1 = std::clock();
  auto cnt = count(nums);
  std::cout << cnt << "\t";
  auto t2 = std::clock();

  auto ret = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000;

  return ret;
}

int main() {
  for (std::size_t i = 250; true; i += i) {
    double time = timeTrial(i);
    std::printf("%15lu\t%15.2f\n", i, time);
  }

  return 0;
}
