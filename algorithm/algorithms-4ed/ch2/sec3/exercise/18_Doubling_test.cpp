#include "18_Median_of_3_partitioning.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

double timeTrial(int N) {
  const int MAX = 100000000;
  std::vector<double> a;

  for (int i = 0; i < N; ++i) {
    auto ret = (static_cast<double>(rand()) / RAND_MAX * (MAX - -MAX) + -MAX);
    a.push_back(ret);
  }

  Quick<double> quick;
  auto t1 = clock();
  quick.sort(a);
  auto t2 = clock();

  return static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
}

int main() {
  for (int N = 250; true; N += N) {
    auto time = timeTrial(N);
    printf("%7d %5.2f\n", N, time);
  }

  return 0;
}
