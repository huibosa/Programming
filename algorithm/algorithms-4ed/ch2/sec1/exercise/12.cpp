/* 2.1.12  Instrument shellsort to print the number of compares divided by the array size */ 
/* for each increment. Write a test client that tests the hypothesis that this number is a */ 
/* small constant, by sorting arrays of random Double values, using array sizes that are */ 

#include <iostream>
#include <vector>
#include <cassert>

class Shell {
public:
  void sort(std::vector<double>& a);
  bool isSorted(const std::vector<double>& a);
  void show(const std::vector<double>& a) const;
private:
  bool less(double v, double w);
  void exch(std::vector<double>& a, double i, double j);
private:
  int compareCount = 0;
};

inline void Shell::exch(std::vector<double>& a, double i, double j) {
  auto tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

inline void Shell::show(const std::vector<double>& a) const {
  for (double i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
};

inline bool Shell::less(double v, double w) {
  ++compareCount;
  return v < w;
};

inline bool Shell::isSorted(const std::vector<double>& a) {
  for (double i = 0; i < a.size(); ++i) {
    if (less(a[i], a[i-1])) {
      return false;
    }
  }
  return true;
}

inline void Shell::sort(std::vector<double>& a) {
  auto n = a.size();
  
  // or store increment sequence in an array
  auto h = 1;
  while (h < n/3) {
    h = 3 * h + 1;
  }

  while (h >= 1) {
    for (int i = h; i < n; ++i) {
      for (int j = i; j >= h && less(a[j], a[j-h]); j -= h) {
        exch(a, j, j-h);
      }
    }
    h /= 3;
    std::cout << compareCount / a.size() << " ";
  }
  std::cout << "\n";
  std::cout << "\n";
};


static double randUniform(double min, double max) {
  auto ret = rand() / static_cast<double>(RAND_MAX) * (max - min) + min;

  return ret;
}

static std::vector<double> initArray(int n) {
  std::vector<double> ret;
  for (int i = 0; i < n; ++i) {
    ret.push_back(randUniform(-1, 1));
  }
  return ret;
}

int main() {
  
  for (int n = 10;; n *= 10) {
    auto a = initArray(n);
    Shell shell;
    std::cout << "Array of size " << n << ":\n";
    shell.sort(a);
  }

  return 0;
}
