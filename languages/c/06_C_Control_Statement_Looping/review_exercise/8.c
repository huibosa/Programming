#include <stdio.h>
int main(void)
{
    float num1, num2;

    printf("Enter two float number:\n");
    
    while (scanf("%f%f", &num1, &num2))
    {
        printf("%f\n", (num1 - num2) / (num1 * num2));
        printf("Enter two float number:\n");
    }

    return 0;
}
