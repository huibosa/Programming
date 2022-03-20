#include <iostream>
#include <string>

static int gcd(int a, int b) {
  if (b == 0) { return a; }

  auto r = a % b;
  return gcd(b, r);
}

static bool coPrime(int a, int b) {
  return gcd(a, b) == 1 ? true : false;
}

int main(int argc, char** argv) {
  auto rowCount = std::stoi(argv[1]);
  auto colCount = std::stoi(argv[2]);

  auto matrix = new char*[rowCount]();
  for (int i = 0; i < rowCount; ++i) {
    matrix[i] = new char[colCount];
  }

  for (int r = 0; r < rowCount; r++) {
    for (int c = 0; c < rowCount; c++) {
      if (coPrime(r, c)) { matrix[r][c] = 'T'; }
      else { matrix[r][c] = 'F'; }
    }
  }

  for (int r = 0; r < rowCount; r++) {
    for (int c = 0; c < rowCount; c++) {
      std::cout << matrix[r][c] << "  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }

  for (int i = 0; i < rowCount; ++i) {
    delete [] matrix[i];
  }
  delete [] matrix;
}
