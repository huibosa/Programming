// The harmonic mean of two numbers is obtained by taking the inverses of the
// two numbers, averaging them, and taking the inverse of the result. Use a
// #define directive to define a macro “function” that performs this operation.
// Write a simple program that tests the macro.


#include <stdio.h>
#define HARMONIC_MEAN(X,Y) (1/((1/(X)+1/(Y))/2))

int main(void)
{
    double x = 2;
    double y = 3;
    double result;

    result = HARMONIC_MEAN(x, y);

    printf("%lf\n", result);

    return 0;
}
