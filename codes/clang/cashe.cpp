#include <chrono>
#include <iostream>
#include <math.h>
using namespace std::chrono;

const int total_buff_count = 16;
const int buff_size        = 32 * 1024 * 1024;

int testCacheHit(int* pBuffer, int size, int step) {
  int result = 0;
  for (int i = 0; i < size;) {
    result += pBuffer[i];
    i += step;
  }

  return result;
}

int main() {
  int* pBuffer = new int[buff_size * total_buff_count];

  for (int i = 0; i < total_buff_count; ++i) {
    int step = (int)pow(2, i);

    auto         start = std::chrono::system_clock::now();
    volatile int result =
        testCacheHit(pBuffer + buff_size * i, buff_size, step);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "step: " << step
              << ", elapsed time: " << elapsed_seconds.count() * 1000 << "ms\n";
  }

  delete[] pBuffer;
}
