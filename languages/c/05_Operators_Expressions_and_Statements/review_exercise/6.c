#include <stdio.h>
double cube(double n);
int main(void)
{
    double num;

    scanf("%lf", &num);
    printf("%g\n", cube(num));
}

double cube(double n)
{
    return n * n *n;
}
