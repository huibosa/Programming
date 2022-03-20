#pragma once

#include <string>

class Counter {
public:
  Counter() = default;
  Counter(const std::string &s) : name(s) {}

public:
  void increment() { count++; }
  int tally() const { return count; }
  std::string toString() const { return std::to_string(count) + " " + name; }
  int compareTo(const Counter &that) const;

private:
  std::string name;
  int count = 0;
};

inline int Counter::compareTo(const Counter &that) const {
  if (this->count < that.count) { return false; }
  else if (this->count > that.count) { return +1; }
  else { return 0; }
}
