#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <bits/types/clock_t.h>
#include <cstddef>
#include <cstdlib>
#include <ctime>

class StopWatch {
public:
  StopWatch() { start = clock(); }
  double elapsedTime();
private:
  clock_t start;
};

inline double StopWatch::elapsedTime() {
  clock_t now = clock();
  return static_cast<double>(now - start) / CLOCKS_PER_SEC;
}

#endif /* STOPWATCH_H */
