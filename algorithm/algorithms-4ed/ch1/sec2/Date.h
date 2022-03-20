#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  friend bool operator==(const Date &lhs, const Date &rhs);
  friend bool operator!=(const Date &lhs, const Date &rhs);
  friend bool operator>(const Date &lhs, const Date &rhs);
  friend bool operator<(const Date &lhs, const Date &rhs);

public:
  Date(int m, int d, int y) : month(m), day(d), year(y) {}

public:
  Date(const std::string &date);
public:
  int getMonth() const { return month; }
  int getday() const { return day; }
  int getYear() const { return year; }
  Date next() const;
  int hashCode() const;
  std::string toString() const;

private:
  bool isValid(int m, int d, int y) const;
  bool isLeapYear(int y) const;

private:
  int month;
  int day;
  int year;
};

#endif /* end of include guard: DATE_H */
