#include <stdio.h>

int Fibonacci(int n);

int main(void)
{
}

int Fibonacci(int n)
{
    int old_term = 0;
    int new_term = 1;
    int temp;

    if (n == 0)
        return 0;

    while (n--) {
        temp = new_term;
        new_term += old_term;
        old_term = temp;
    }

    return new_term;
}

