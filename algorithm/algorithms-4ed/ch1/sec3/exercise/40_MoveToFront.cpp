#include <algorithm>
#include <iostream>
#include <memory>
#include <list>
#include <algorithm>

void printList(std::list<int>& numbers) {
  std::cout << "The list now: " << std::endl;
  for (const auto& num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> numbers;
  int temp;

  while (std::cin >> temp) {
    auto res = std::find(numbers.cbegin(), numbers.cend(), temp);

    if (res == numbers.end()) {
      numbers.push_front(temp);
      printList(numbers);
    } else {
      numbers.erase(res);
      numbers.push_front(temp);
      printList(numbers);
    }
  }

  return 0;
}
