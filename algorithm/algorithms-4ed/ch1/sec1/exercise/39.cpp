#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

auto getRandom(long n) { return rand() % n; }

auto pVector(long n) {
  auto ret = new std::vector<long>();
  ret->reserve(n);

  for (int i = 0; i < n; ++i) {
    ret->push_back(getRandom(n));
  }

  return ret;
}

auto duplicates(long n) {
  auto pv1 = pVector(n);
  auto pv2 = pVector(n);

  std::sort(pv1->begin(), pv1->end());
  std::sort(pv2->begin(), pv2->end());

  long count = 0;
  for (int ix = 0; ix != pv1->size(); ++ix) {
    if (pv1->at(ix) == pv2->at(ix))
      count++;
  }

  delete pv1;
  delete pv2;

  return count;
}

int main(int argc, char** argv) {
  auto T = std::stoi(argv[1]);

  for (int i = 0; i < T; ++i) {
  }

  return 0;
}
