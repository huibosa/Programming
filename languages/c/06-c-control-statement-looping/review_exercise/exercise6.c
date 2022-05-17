#include <stdio.h>
int main(void)
{
    int upper, lower, i;

    printf("Enter the upper limit: ");
    scanf("%d", &upper);
    printf("Enter the lower limit: ");
    scanf("%d", &lower);

    printf("+---------------+---------------+---------------+\n"
           "|       n       |       n^2     |       n^3     |\n"
           "+---------------+---------------+---------------+\n",);

    for (i = lower; i < upper; i++)
        printf("|%8d |%8d |%8d |\n", i, i*i, i*i*i);
    printf("+---------------+---------------+---------------+\n");

    return 0;
}
