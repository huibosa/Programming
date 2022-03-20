#include "05_Book.h"

bool operator==(const Book& lhs, const Book& rhs) {
  if (lhs.author_ == rhs.author_
      && lhs.isbn_ == rhs.isbn_
      && lhs.name_ == rhs.name_
      && lhs.pubDate_ == rhs.pubDate_) {
    return true;
  }
  
  return false;
}

bool operator!=(const Book& lhs, const Book& rhs) {
  return !(lhs == rhs);
}

Book& Book::operator=(const Book &that) {
  this->author_ = that.author_;
  this->isbn_ = that.isbn_;
  this->name_ = that.name_;
  this->pubDate_ = that.pubDate_;

  return *this;
}

std::istream& operator>>(std::istream& is, Book& rhs) {
  is >> rhs.isbn_ >> rhs.name_ >> rhs.author_ >> rhs.pubDate_;

  return is;
}

std::ostream& operator<<(std::ostream& os, const Book& rhs) {
  os << rhs.isbn_ << " " << rhs.name_ << " " << rhs.author_ << " " << rhs.pubDate_;

  return os;
}
