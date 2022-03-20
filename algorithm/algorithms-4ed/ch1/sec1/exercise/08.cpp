// What do each of the following print?
// 
//   a. System.out.println('b');
//   b. System.out.println('b' + 'c');
//   c. System.out.println((char) ('a' + 4));

#include <iostream>

int main() {
  std::cout << 'b' << "\n";       // b
  std::cout << 'b' + 'c' << "\n"; // 197
  std::cout << static_cast<char>('a' + 4) << "\n";  // e

  return 0;
}
