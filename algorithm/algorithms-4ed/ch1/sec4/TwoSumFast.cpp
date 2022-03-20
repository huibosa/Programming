#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <ctime>


int TwoSumFast(std::vector<int> a) {
  int cnt = 0;
  std::sort(a.begin(), a.end());

  for (int i = 0; i < a.size() && a[i] < 0; ++i) {
    if (std::binary_search(a.begin() + i, a.end(), -a[i])) {
      cnt++;
    }
  }

  return cnt;
}

double timeTrial(int N) {
  const int MAX = 1000000;
  std::vector<int> nums;

  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> distr(-MAX, MAX);

  nums.reserve(1000000);
  for (int i = 0; i < N; i++) {
    nums.push_back(distr(generator));
  }

  auto t1 = std::clock();  // count start
  auto cnt = TwoSumFast(nums);
  std::cout << cnt << "\t";
  auto t2 = std::clock();  // count end

  auto ms_double = t2 - t1;

  /* return ms_double.count(); */
  return static_cast<double>(ms_double ) / CLOCKS_PER_SEC * 1000;
}

int main() {
  for (int i = 10000; i < 10000000; i += 10000) {
    double time = timeTrial(i);
    std::printf("%15d\t%15.2f\n", i, time);
  }

  return 0;
}
