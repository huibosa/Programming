#include <chrono>
#include <iostream>
#include <ratio>
#include <thread>

void long_peration() {
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(150ms);
}

int main() {
  auto t1 = std::chrono::high_resolution_clock::now();
  long_peration();
  auto t2 = std::chrono::high_resolution_clock::now();

  auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

  std::chrono::duration<double, std::milli> ms_double = t2 - t1;

  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";

  return 0;
}
