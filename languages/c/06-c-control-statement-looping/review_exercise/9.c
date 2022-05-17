#include <stdio.h>
float foo(float num1, float num2);
int main(void)
{
    float num1, num2;

    printf("Enter two float number:\n");
    
    while (scanf("%f%f", &num1, &num2))
    {
        printf("%f\n", foo(num1, num2));
        printf("Enter two float number:\n");
    }

    return 0;
}

float foo(float num1, float num2)
{
    return (num1 - num2) / (num1 + num2);
}
