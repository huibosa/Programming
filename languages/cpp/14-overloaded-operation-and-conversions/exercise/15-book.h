/* Exercise 14.8: Define an output operator for the class you chose in exercise */
/* 7.40 from 7.5.1 */
 

#pragma once

#include <iostream>
#include <istream>
#include <string>

class Book {
friend std::istream& operator>>(std::istream& is, Book& rhs);
friend std::ostream& operator<<(std::ostream& os, const Book& rhs);
friend bool operator==(const Book& lhs, const Book& rhs);
friend bool operator!=(const Book& lhs, const Book& rhs);
friend bool operator<(const Book& lhs, const Book& rhs);
friend bool operator>(const Book& lhs, const Book& rhs);
friend Book operator+(const Book& lhs, const Book& rhs);
public:
  Book(unsigned isbn, const std::string& name, const std::string& author, const std::string& pubDate, unsigned number)
    :isbn_(isbn), name_(name), author_(author), pubDate_(pubDate), number_(number) {  }
public:
  explicit Book(std::istream& is) {
    is >> isbn_ >> name_ >> author_ >> pubDate_;
  }
public:
  Book& operator=(const Book& rhs);
  Book& operator+=(const Book& rhs);
private:
  unsigned isbn_;
  std::string name_;
  std::string author_;
  std::string pubDate_;
  unsigned number_;
};

std::istream& operator>>(std::istream& is, Book& rhs);
std::ostream& operator<<(std::ostream& os, const Book& rhs);
bool operator==(const Book& lhs, const Book& rhs);
bool operator!=(const Book& lhs, const Book& rhs);
bool operator<(const Book& lhs, const Book& rhs);
bool operator>(const Book& lhs, const Book& rhs);
