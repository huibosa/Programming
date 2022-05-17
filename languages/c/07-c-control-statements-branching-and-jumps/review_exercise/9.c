#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(unsigned i);

int main(void)
{
    unsigned num;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    for (unsigned i = 2; i <= num; i++) {
        if (is_prime(i))
            printf("%u\n", i);
    }
    return 0;
}

bool is_prime(unsigned i)
{
    for (unsigned j = 2; j * j <= i; j++) {
        if (i % j == 0)
            return false;
    }
    return true;
}
