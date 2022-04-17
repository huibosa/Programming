#include <iostream>
#include <string>

class Book {
public:
  Book(unsigned isbn, const std::string& name, const std::string& author, const std::string& pubDate)
    :isbn_(isbn), name_(name), author_(author), pubDate_(pubDate) {  }
public:
  explicit Book(std::istream& is) {
    is >> isbn_ >> name_ >> author_ >> pubDate_;
  }
private:
  unsigned isbn_;
  std::string name_;
  std::string author_;
  std::string pubDate_;
};
