/* Define a vector<String> and call push_back several */
/* times on that vector. Run your program and see how often Strings are */
/* copied. */

#include "47_String.h"
#include <vector>
#include <iostream>

void foo(String x) {
  std::cout << x.c_str() << "\n";
}

void bar(const String& x) {
  std::cout << x.c_str() << "\n";
}

String baz() {
  String ret("world");
  return ret;
}

int main() {
  char text[] = "world";

  String s0;
  String s1("hello");
  String s2(s0);
  String s3 = s1;
  String s4(text);
  s2 = s1;

  foo(s1);
  bar(s1);
  foo("temporary");
  bar("temporary");
  String s5 = baz();

  std::vector<String> svec;
  svec.reserve(8);
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back(s2);
  svec.push_back(s3);
  svec.push_back(s4);
  svec.push_back(s5);
  svec.push_back(baz());
  svec.push_back("good job");

  for (const auto& s : svec) {
    std::cout << s.c_str() << "\n";
  }

  return 0;
}
