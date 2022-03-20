/* 1.1.21 Write a program that reads in lines from standard input with each line contain- */
/* ing a name and two integers and then uses printf() to print a table with a column of */
/* the names, the integers, and the result of dividing the first by the second, accurate to */
/* three decimal places. You could use a program like this to tabulate batting averages for */
/* baseball players or grades for students. */

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

void formattedPrint(std::vector<std::string> values) {
  printf("%8s", values[0].c_str());
  printf("%8s", values[1].c_str());
  printf("%8s", values[2].c_str());

  double value1 = std::stod(values[1]);
  double value2 = std::stod(values[2]);
  double result = value1 / value2;
  printf("%7.3f \n", result);
}

// paremeter example:
// Rene 2 1
// Bacon 4 3
// Abcdef 6 2

int main(int argc, char** argv) {
  printf("%8s %7s %7s %7s", "Names", "Number1", "Number2", "Result\n");

  std::vector<std::string> values;
  for (int i = 1; i < argc; ++i) {
    values.push_back(std::string(argv[i]));
  }
  
  formattedPrint(values);

  return 0;
}
