#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "25_Cutoff_to_insertion_sort.h"

int main() {
  const int n = 1000000;
  
  std::vector<int> a;
  for (int i = 0; i < n; ++i) {
    a.push_back(rand() % 100000);
  }

  QuickInsertion<int> quick;
  quick.sort(a);

  /* auto t1 = clock(); */
  /* MergeImprove<int> merge; */
  /* merge.sort(a); */
  /* auto t2 = clock(); */
  
  /* std::vector<int> b; */
  /* for (int i = 0; i < n; ++i) { */
  /*   b.push_back(rand() % n); */
  /* } */

  /* auto t3 = clock(); */
  /* MergeTD<int> merge1; */
  /* merge1.sort(b); */
  /* auto t4 = clock(); */

  /* auto timer1 = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC; */
  /* auto timer2 = static_cast<double>(t4 - t3) / CLOCKS_PER_SEC; */

  /* std::cout << "MergeImprove : " << timer1 << "\n"; */
  /* std::cout << "Merge : " << timer2 << "\n"; */

  for (const auto& i : a) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
