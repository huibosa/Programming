#include <cstdlib>
#include <iostream>
#include <memory>
#include "Stack.h"

int main() {
  auto ps = std::make_shared<Stack>();

  for (int i = 0; i < 9999; ++i) {
    ps->push(i);
  }

  while (!ps->isEmpty()) {
    ps->pop();
  }

  return 0;
}
