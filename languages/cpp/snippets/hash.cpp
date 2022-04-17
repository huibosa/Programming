#include <iostream>

const int R = 29310;

template <typename _Tp, unsigned _Nm>
constexpr int getArraySize(const _Tp (&)[_Nm]) {
  return _Nm;
}

int hash(int M, char * str, int n) {
  int hash = 0;
  
  for (int i = 0; i < n-1; ++i) {
    hash = (R * hash + str[i]) % M;
  }

  return hash;
}

int main() {
  char str[] = "hello";
  std::cout << hash(173, str, getArraySize(str)) << "\n";

  return 0;
}
