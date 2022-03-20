#include <stdio.h>
int main(void)
{
    unsigned int un = 3000000000;       /* system with 32-bit int */
    short end = 200;                    /* and 16-bit short */
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u and not %d\n", un, un);
    printf("%hd and %d\n", end, end);
    printf("%ld and not %ld\n", big, big);
    printf("%lld and not %lld\n", verybig, verybig);

    return 0;
}
