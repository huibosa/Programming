#include <stdio.h>
double get_power(int base, int exponent);

int main(void)
{
    int base, exponent, result;

    printf("Enter two numbers (q to quit): ");
    while (scanf("%d%d", &base, &exponent)) {
        while (getchar() != '\n')
            continue;

        printf("%d to the %d power is %.4lf\n",
                base, exponent, get_power(base, exponent));
        printf("Enter next two number (q to quit): ");
    }

    return 0;

}

double get_power(int base, int exponent)
{
    int result = 1;

    if (exponent > 0) {
        for (int i = 0; i < exponent; i++)
            result *= base;
        return result;
    } else if (exponent < 0) {
        for (int i = 0; i < -exponent; i++)
            result *= base;
        return (1.0 / result);
    } else {
        if (base == 0)
            return 1;
        else
            return 0;
    }

    return result;

}
