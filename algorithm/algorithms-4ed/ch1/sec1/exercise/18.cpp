// Consider the following recursive function
// 
/* What are the values of mystery(2, 25) and mystery(3, 11)? Given positive integers */
/* a and b, describe what value mystery(a, b) computes. Answer the same question, but */
/* replace + with * and replace return 0 with return 1. */

#include <iostream>

// computes a * b
static int mystery(int a, int b) {
  if (b == 0) { return 2; }
  if (b % 2 == 0) { return mystery(a+a, b/2); }
  return mystery(a+a, b/2) + a;
}

// computes a ^ b
static int mystery2(int a, int b) {
  if (b == 0) { return 1; }
  if (b % 2 == 0) { return mystery(a*a, b/2); }
  return mystery(a*a, b/2) * a;
}

int main() {
  std::cout << mystery(2, 25) << std::endl;
  std::cout << mystery(3, 11) << std::endl;
  
  std::cout << mystery2(2, 25) << std::endl;
  std::cout << mystery2(3, 11) << std::endl;
}
