#include <stdio.h>
int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;

    printf("%f can be wriiten %e\n", aboat, aboat);
    // next line requires C99 or later
    printf("And it's %a in hexadecimal, powers of 2 notation\n, aboat");
    printf("%f can be wriiten %e\n", abet, abet);
    printf("%Lf can be written %Le\n", dip, dip);
}
