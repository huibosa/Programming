#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "inc/Quick3Way.h"
#include "inc/Quick.h"
#include "inc/ArrayGenerator.h"
#include "inc/StopWatch.h"
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  int arrayLength = std::stoi(argv[1]);
  
  auto ag = ArrayGenerator<int>();
  auto vec = ag.generateRandomArrayWith2Values(arrayLength);
  /* auto vec = ag.generateRandomArray(arrayLength); */

  Quick<int> quick1;
  Quick3Way<int> quick2;
  
  std::random_device rand_dev;
  std::mt19937 rng(rand_dev());
  
  std::shuffle(vec.begin(), vec.end(), rng);
  
  StopWatch timer1;
  quick1.sort(vec);
  auto t1 = timer1.elapsedTime();
  
  std::shuffle(vec.begin(), vec.end(), rng);
  
  StopWatch timer2;
  quick2.sort(vec);
  auto t2 = timer2.elapsedTime();

  std::cout << "Time for quick: " << t1  << "\n";
  std::cout << "Time for quick3Way: " << t2 << "\n";

  return 0;
}
