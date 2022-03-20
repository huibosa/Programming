/* Give the copy constructor and copy-assignment operator in */
/* your String class from exercise 13.44 in § 13.5 (p. 531) a statement that */
/* prints a message each time the function is executed. */

#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <memory>
#include <string>
#include <utility>
#include <iostream>

class String {
public:
  String(): String("") {}
  String(const String &rhs);
  String(const char *ps);
  String &operator=(const String &rhs);
  ~String();

public:
  char *c_str() const { return front; }
  size_t size() { return rear - front; }
  size_t length() { return rear - front - 1; }

private:
  void free();
  std::pair<char*, char*> alloc_n_copy(char * b, char * e);

private:
  std::allocator<char> alloc;
  char *front;  // start of cstring
  char *rear;   // one past cstring end
};

#endif /* STRING_H */
