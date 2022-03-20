#include <stdio.h>
int main(void)
{
    int i, j, list[10];

    for (i = 0; i < 10; i++)
    {
        list[i] = 2 * i + 3;
        for (j = 1; j <= i; j++)
            printf(" %d", list[j]);
        printf("\n");
    }
}
