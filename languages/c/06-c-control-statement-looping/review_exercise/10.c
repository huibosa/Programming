#include <stdio.h>
int foo(int num1, int num2);
int main(void)
{
    int lower, upper;

    printf("Enter lower and upper integer limits: ");
    while (scanf("%d%d", &lower, &upper))
    {
        printf("The sum of the squares from %d to %d is %d\n",
                lower*lower, upper*upper, foo(lower, upper));
        printf("Enter lower and upper integer limits: ");
    }
    return 0;
}

int foo(int num1, int num2)
{
    int i;
    int sum = 0;
    
    for (i = num1; i <= num2; i++)
        sum += i * i;

    return sum;
}
