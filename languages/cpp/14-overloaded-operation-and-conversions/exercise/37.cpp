/* Write a class that tests whether two values are equal. Use */
/* that object and the library algorithms to write a program to replace all */
/* instances of a given value in a sequence. */

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

class IsEqual {
public:
  IsEqual(int v): val(v) {  }
  bool operator()(int n) const { return val == n; }

private:
  int val;
};

int main() {
  std::vector<int> seq{1,2,3,2,2,1,3,4,5,5,2};

  std::replace_if(seq.begin(), seq.end(), IsEqual(2), 10);

  std::copy(seq.begin(), seq.end(), std::ostream_iterator<int>(std::cout, " "));

  return 0;
}
