#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <chrono>
#include <ratio>
#include <vector>

int count(const std::vector<int>& a) {
  int N = a.size();
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N ; ++k) {
        if (a[i] + a[j] + a[k] == 0) {
          cnt++;
        }
      }
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

  for (int i = 0; i < N; i++) {
    nums.push_back(distr(generator));
  }

  auto t1 = clock();
  auto cnt = count(nums);
  auto t2 = clock();

  auto ret = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;

  return ret;
}

int main() {
  for (int i = 250; true; i += i) {
    double time = timeTrial(i);
    std::printf("%7d %5.1f\n", i, time);
  }

  return 0;
}
