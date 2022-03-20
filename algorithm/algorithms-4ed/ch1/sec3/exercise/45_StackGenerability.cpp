#include <iostream>
#include <memory>
#include <string>
#include <stack>

bool willTheStackUnderflow(const std::string& inputValues) {
  int itemsCount = 0;

  for (const auto& input : inputValues) {
    if (input == '-') { itemsCount--; }
    else { itemsCount++; }

    if (itemsCount < 0) { return true; }
  }

  return false;
}

bool canAPermutationBeGenerated(const std::string& permutaion) {
  auto ps = std::make_shared<std::stack<int>>();
  int current = 0;

  for (const auto& value : permutaion) {
    auto integerValue = value - '0';

    if (ps->empty() || integerValue > ps->top()) {
      while (current < integerValue) {
        ps->push(current);
        current++;
      }
      current++;
    } else if (integerValue == ps->top()) {
      ps->pop();
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  /* std::string inputValues{"012---345--6---"}; */
  /* std::cout << "Input 1 - Will Underflow? "; */
  /* std::cout << (willTheStackUnderflow(inputValues) ? "Yes" : "No") */
  /*           << std::endl; */

  std::string inputValues{"4687532901"};
  std::cout << "Input: 4 6 8 7 5 3 2 9 0 1" << std::endl;
  std::cout << (canAPermutationBeGenerated(inputValues) ? "Yes" : "false")
            << std::endl;

  return 0;
}
