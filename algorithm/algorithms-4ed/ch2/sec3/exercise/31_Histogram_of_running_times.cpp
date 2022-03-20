#include <iostream>
#include <string>
#include "inc/Quick.h"
#include "inc/StopWatch.h"
#include "inc/ArrayGenerator.h"

double getRunningTime(int N, int T) {
  ArrayGenerator<double> ag;
  Quick<double> quick;
  double totalRunningTime = 0;

  for (int i = 0; i < T; ++i) {
    auto arr = ag.generateRandomArray(N, 0.0, 10000000.0);
    
    StopWatch timer;
    quick.sort(arr);
    auto t = timer.elapsedTime();
    
    totalRunningTime += t;
  }

  return totalRunningTime;
}

int main(int argc, char** argv) {
  const auto T = std::stoi(argv[1]);

  for (int n = 10e3; n <= 10e6; n *= 10) {
    auto t = getRunningTime(n, T);
    std::cout << t << "\n";
  }

  return 0;
}
