/* Exercise 14.5: In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of */
/* one of the following classes. Decide what, if any, overloaded operators your */
/* class should provide. */
 
/* (a) Book */
/* (b) Date */
/* (c) Employee */
/* (d) Vehicle */
/* (e) Object */
/* (f) Tree */
 

#pragma once

#include <iostream>
#include <istream>
#include <string>

class Book {
friend std::istream& operator>>(std::istream& is, Book& rhs);
friend std::ostream& operator<<(std::ostream& os, const Book& rhs);
friend bool operator==(const Book& lhs, const Book& rhs);
friend bool operator!=(const Book& lhs, const Book& rhs);
public:
  Book(): Book(0, "", "", "") {  }
  Book(unsigned isbn, const std::string& name, const std::string& author, const std::string& pubDate)
    :isbn_(isbn), name_(name), author_(author), pubDate_(pubDate) {  }
public:
  explicit Book(std::istream& is) {
    is >> isbn_ >> name_ >> author_ >> pubDate_;
  }
public:
  Book& operator=(const Book& rhs);
private:
  unsigned isbn_;
  std::string name_;
  std::string author_;
  std::string pubDate_;
};

std::istream& operator>>(std::istream& is, Book& rhs);
std::ostream& operator<<(std::ostream& os, const Book& rhs);
bool operator==(const Book& lhs, const Book& rhs);
bool operator!=(const Book& lhs, const Book& rhs);
