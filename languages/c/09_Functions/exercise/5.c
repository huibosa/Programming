#include <stdio.h>
void larger_of(double * x, double * y);

int main(void)
{
    double x, y;

    printf("Enter two numbers: ");
    while (scanf("%lf%lf", &x, &y) != 2) {
        while (getchar() != '\n')
            continue;
        printf("Please enter the correct number: ");
    }

    larger_of(&x, &y);
    printf("Now x = %.2lf, y = %.2lf", x, y);

}

void larger_of(double * x, double * y)
{
    double temp;

    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}
