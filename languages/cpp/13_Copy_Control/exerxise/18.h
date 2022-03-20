/* Define an Employee class that contains an employee name */
/* and a unique employee identifier. Give the class a default constructor and a */
/* constructor that takes a string representing the employee’s name. Each */
/* constructor should generate a unique ID by incrementing a static data */
/* member. */

#pragma once

#include <string>

class Employee {
public:
  Employee();
  Employee(const std::string& s);
private:
  std::string name;
  int id;
  static int unique;
};
