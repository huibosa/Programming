#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"
#include "24_Insertion_sort_with_sentinel.h"
#include "Merge_top_down.h"

template<typename _Tp>
class SortCompare {
public:
  double time(const std::string& alg, std::vector<_Tp> a) {
    auto t1 = clock();

    if (alg == "Insertion") {
      Insertion<_Tp> insertion;
      insertion.sort(a);
    }
    else if (alg == "Selection") {
      Selection<_Tp> selection;
      selection.sort(a);
    }
    else if (alg == "Shell") {
      Shell<_Tp> shell;
      shell.sort(a);
    }
    else if (alg == "Sentinel") {
      Sentinel<_Tp> Sentinel;
      Sentinel.sort(a);
    }
    else if (alg == "Merge") {
      Merge<_Tp> merge;
      merge.sort(a);
    }
    /* if (alg == "Quick") { */
    /* } */
    /* if (alg == "Heap") { */
    /* } */
    
    auto t2 = clock();

    return static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
  }

  double timeRandomInput(const std::string& alg, int size, int times) {
    double total = 0.0;

    std::vector<_Tp> a(size);
    for (int i = 0; i < times; ++i) {
      for (int j = 0; j < size; ++j) {
        a[j] = randUniform(0., 1.);
      }
      total += time(alg, a);
    }
    return total;
  }
private:
  _Tp randUniform(_Tp min, _Tp max) {
    /* return rand() / static_cast<_Tp>(RAND_MAX) * (max - min) + min; */
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_real_distribution<_Tp> distr(min, max);

    return distr(g);
  }
};

int main(int argc, char** argv) {
  std::string alg1 = argv[1];
  std::string alg2 = argv[2];
  int size = std::stoi(argv[3]);
  int times = std::stoi(argv[4]);

  SortCompare<double> sc;
  double t1 = sc.timeRandomInput(alg1, size, times);
  double t2 = sc.timeRandomInput(alg2, size, times);

  printf("For %d random Doubles\n   %s is", size, alg1.c_str());
  printf(" %.1f times fater than %s\n", t2/t1, alg2.c_str());

  return 0;
}
