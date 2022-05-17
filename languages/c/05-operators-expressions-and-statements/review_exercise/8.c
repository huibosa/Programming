#include <stdio.h>
double temperature(double f);
int main(void)
{
    double temp;
    printf("Please enter ther temperature in Fahrenheit: ");

    while(scanf("%lf", &temp) == 1)
    {
        temperature(temp);
        printf("Please enter ther next temperature in Fahrenheit: ");
    }
}

double temperature(double f)
{
    const float coefficient_1 = 5.0;
    const float coefficient_2 = 9.0;
    const float coefficient_3 = 32.0;
    const float coefficient_4 = 273.16;

    double c, k;

    c = coefficient_1 / coefficient_2 * (f - coefficient_3);
    k = c + coefficient_4;

    printf("%.2lf is %.2lf in celsius, and %.2lf in kelvin\n", f, c, k);
}
