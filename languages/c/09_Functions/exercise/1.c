#include <stdio.h>
double min(double x, double y);
int main(void)
{
    printf("%f", min(5, 7));

    return 0;
}

double min(double x, double y)
{
    double MIN = x;
    if (y < x)
        MIN = y;

    return MIN;
}
