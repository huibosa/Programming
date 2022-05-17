/* showf_pt.c -- displays float value in two ways */
#include <stdio.h>
int main(void)
{
    float a = 32000.0;
    double b = 2.14e9;
    long double c = 5.32e-5;

    printf("%f can be written %e\n", a, a);
    printf("And it's %a in hxadecimal, powers of 2 notation\n", a);
    printf("%f can be written %le\n", b, b);
    printf("%Lf can be written %Le\n", c, c);

    return 0;
}
