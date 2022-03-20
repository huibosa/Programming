#include "11_Quick.h"
#include "inc/StopWatch.h"
#include "inc/ArrayGenerator.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void printResults(int arraySize, double runningTime, double runningTimeRatio) {
  printf("%10d %15.1f %9.1f\n", arraySize, runningTime, runningTimeRatio);
}

int main() {
  
  printf("%13s %12s %6s\n", "Array Size | ", "Running Time | ", "Ratio");

  int arraySize = 200;
  Quick<int> quick;
  ArrayGenerator<int> ag;
  auto arr = ag.randomArrayGenerator(arraySize/2);

  StopWatch initialTimer;
  quick.sort(arr);
  auto previousRunningTime = initialTimer.elapsedTime();
  
  for (; true; arraySize *= 2) {
    auto arr = ag.randomArrayGenerator(arraySize);
    
    StopWatch timer;
    quick.sort(arr);
    auto runningTime = timer.elapsedTime();

    auto runningTimeRatio = runningTime / previousRunningTime;
    printResults(arraySize, runningTime, runningTimeRatio);
    previousRunningTime = runningTime;
  }

  return 0;
}
