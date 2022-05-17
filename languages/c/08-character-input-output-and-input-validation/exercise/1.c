#include <stdio.h>
int main(void)
{
    unsigned count;

    while (getchar() != '\n')
        count++;

    printf("%u\n", count);
}
