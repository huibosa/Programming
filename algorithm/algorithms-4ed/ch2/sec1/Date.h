#ifndef DATE_H
#define DATE_H

#include <functional>

class Date {
public:
  Date(int d, int m, int y): day(d), month(m), year(y) {  }
public:
  int getDay() const { return day; }
  int getMonth() const { return month; }
  int getYear() const { return year; }
public:
  int compareTo(Date that) const;
private:
  int day;
  int month;
  int year;
};

inline int Date::compareTo(Date that) const {
  if (year < that.year) { return -1; }
  if (year > that.year) { return +1; }
  if (month < that.month) { return  -1; }
  if (month > that.month) { return  +1; }
  if (day < that.day) { return  -1; }
  if (day > that.day) { return  +1; }
  return 0;
}

#endif /* DATE_H */
