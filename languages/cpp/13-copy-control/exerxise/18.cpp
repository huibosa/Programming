/* Define an Employee class that contains an employee name */
/* and a unique employee identifier. Give the class a default constructor and a */
/* constructor that takes a string representing the employee’s name. Each */
/* constructor should generate a unique ID by incrementing a static data */
/* member. */

#include <string>
#include "18.h"

Employee::Employee() {
  id = unique++;
}

Employee::Employee(const std::string& s): name(s) {
  id = unique++;
}

int Employee::unique = 10;
