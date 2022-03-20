/* Programming Exercise 2-3 */

// Write a program that converts your age in years to days and displays both values. At this
// point, don't worry about fractional years and leap years.


#include <stdio.h>
int main(void)
{
    int age_years;
    int age_days;

    age_years = 26;
    age_days = age_years * 365;

    printf("%d", age_years);
    printf("%d", age_days);

    return 0;
}
