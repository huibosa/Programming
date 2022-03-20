/* Write a class named String that is a simplified version of */
/* the library string class. Your class should have at least a default */
/* constructor and a constructor that takes a pointer to a C-style string. Use
 */
/* ani allocator to allocate memory that your String class uses. */

#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

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
