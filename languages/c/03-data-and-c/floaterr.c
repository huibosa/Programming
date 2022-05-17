/* floaterr.c -- demonstrates round-off error */
#include <stdio.h>
int main(void)
{
    long double a, b;
    
    b = 2.0e20 + 1.0;
    a = b -2.0e20;
    printf("%Lf \n", a);

    return 0;
}
