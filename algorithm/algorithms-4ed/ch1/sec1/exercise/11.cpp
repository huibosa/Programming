/* Write a code fragment that prints the contents of a two-dimensional boolean */
/* array, using * to represent true and a space to represent false. Include row and column */
/* numbers. */

#include <iostream>

int main() {
  char result[10][7] = {
      {true,true,false,true,false,true,true},
      {true,true,true,false,false,true,true},
      {true,true,true,false,false,true,true},
      {true,true,false,true,false,false,false},
      {true,true,true,true,true,true,false},
      {true,true,false,true,false,true,true},
      {true,true,false,false,true,true,true},
      {true,true,false,true,false,true,true},
      {true,true,true,true,false,false,true},
      {true,true,false,true,false,true,true}
  }; 

  auto col = sizeof(result[0]);
  auto row = sizeof(result) / sizeof(result[0]);

  for (int ix = 0; ix < row; ++ix) {
    for (int iv = 0; iv < col; ++iv) {
      if (result[ix][iv]) {
        std::cout << '*' << " ";
      } else {
        std::cout << ' ' << " ";
      }
    }
    std::cout << std::endl;
  }
}
