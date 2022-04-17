/* Use the class from the previous exercise to read the */
/* standard input, storing each line as an element in a vector. */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class GetInput {
public:
  GetInput(std::istream &i = std::cin) : is(i) {}
  std::string operator()() {
    std::string str;
    std::getline(is, str);
    return (is ? str : std::string());
  }
private:
  std::istream& is;
};

int main() {
  GetInput getter;
  std::vector<std::string> lines;

  for (std::string line; !(line = getter()).empty();) {
    lines.push_back(line);
  }
  
  std::for_each(lines.begin(), lines.end(),
               [](const std::string& str) { std::cout << str << " "; });
  std::cout << "\n";

  return 0;
}
