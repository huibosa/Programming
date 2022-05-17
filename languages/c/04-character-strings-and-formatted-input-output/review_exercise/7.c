#include <stdio.h>
int main(void)
{
    float a = 1.0/3.0;
    double b = 1.0/3.0;

    printf("%.4f %.4f\n", a, b);
    printf("%.12f %.12f\n", a, b);
    printf("%.16f %.16f\n", a, b);

    return 0;
}
