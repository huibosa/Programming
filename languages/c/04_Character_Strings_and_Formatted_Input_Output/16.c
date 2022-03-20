#include <stdio.h>
int main(void)
{
    unsigned width, precision;
    int number = 256;
    double weight = 242.5;

    printf("Enter a field width:\n");
    scanf("%u", &width);
    printf("The number is: %*d:\n", width, number);
    printf("Now enter a width and a precision:");
    scanf("%u %u", &width, &precision);
    printf("Weight = %*.*f\nDone!\n", width, precision, weight);

    return 0;
}
