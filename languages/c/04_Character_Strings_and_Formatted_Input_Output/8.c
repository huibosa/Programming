#include <stdio.h>
int main(void)
{
    const double RENT = 3852.99;    // const-style constant

    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%.2f*\n", RENT);
    printf("*%.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3E*\n", RENT);
    printf("*%+8.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);

    return 0;
}
