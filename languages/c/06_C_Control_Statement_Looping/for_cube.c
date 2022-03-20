#include <stdio.h>
int main(void)
{
    int num;

    printf("\tn\tncubed\n");

    for (num = 1; num <= 6; num ++)
        printf("\t%d\t%d\n", num, num * num * num);

    return 0;
}
