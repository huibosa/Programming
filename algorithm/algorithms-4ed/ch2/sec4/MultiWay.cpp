#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <iostream>
#include "IndexMinPQ.h"

void merge(std::vector<std::ifstream>& strms) {
  const int N = strms.size();
  IndexMinPQ<std::string> pq(N);
  std::string str;

  for (int i = 0; i < N; ++i) {
    if (strms[i] >> str) {
      pq.insert(i, str);
    }
  }

  while (!pq.empty()) {
    std::cout << pq.min() << " ";
    int i = pq.rmMin();
    if (strms[i] >> str) {
      pq.insert(i, str);
    }
  }
}

int main(int argc, char** argv) {
  std::vector<std::ifstream> strms;

  for (int i = 1; i < argc; ++i) {
    strms.push_back(std::ifstream(argv[i]));
  }

  merge(strms);

  return 0;
}
