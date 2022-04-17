/* Exercise 16.3: Call your compare function on two Sales_data objects to */
/* see how your compiler handles errors during instantiation. */
 

#include <iostream>

template<typename _Tp>
int compare(const _Tp& lhs, const _Tp& rhs) {
  if (lhs < rhs) { return -1; }
  if (rhs < lhs) { return 1; }
  return 0;
}

class Sales_data {};

int main() {
  Sales_data sd1;
  Sales_data sd2;

  std::cout << compare(sd1, sd2) << "\n";

  return 0;
}
