#include <stdio.h>
int to_base_n(int n, int p);
int main(void)
{
    to_base_n(5, 2);

    putchar('\n');

    return 0;
}

int to_base_n(int n, int p)
{
    int r;
    
    if (n / p > 0)
        to_base_n(n / p, p);
    printf("%d", n % p);

    return 0;
}
