#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>

bool threeSum(const std::vector<int>& a) {
  int N = a.size();
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N ; ++k) {
        if (a[i] + a[j] + a[k] == 0) {
          /* cnt++; */
          return true;
        }
      }
    }
  }
  return false;
}

int twoCount(const std::vector<int>& a) {
  int N = a.size();
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (a[i] + a[j] == 0) {
        cnt++;
      }
    }
  }
  return cnt;
}

int twoCountBinary(std::vector<int>& a) {
  auto cnt = 0;

  std::sort(a.begin(), a.end());

  for (auto i = a.begin(); i != a.end(); ++i) {
    for (auto k = i + 1; k != a.end(); ++k) {
      if (std::binary_search(k, a.end(), -*i)) {
        cnt++;
      }
    }
  }
  return cnt;
}

void binary(std::vector<int>& a) {
  std::sort(a.begin(), a.end());
  std::binary_search(a.begin(), a.end(), 3467);
}

void linear(std::vector<int>& a) {
  auto cnt = 0;

  std::sort(a.begin(), a.end());
  for (const auto& i : a) {
    if (i == 43511) {
      cnt++;
    }
  }
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

  auto t1 = std::clock();
  threeSum(nums); // exexute function
  auto t2 = std::clock();
  auto ret = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000;

  return ret;
}


int main() {
  double prev = timeTrial(1);
  for (int N = 2; true; N += N) {
    double time = timeTrial(N);
    std::printf("%6d %7.1f ", N, time);
    std::printf("%5.1f\n", time / prev);
    prev = time;
  }
}
