#include <stdio.h>
#define SQUARES 64
int main(void)
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;

    printf("square grains total fraction of\n");
    printf("added grains world total\n");
    total = current = 1.0;
    printf("%d\t%.2e\t%.2e\t%.2e\n", count, current, total, total/CROP);

    while (count < SQUARES)
    {
        count = count + 1;
        total = total + current;
        printf("%d\t%.2e\t%.2e\t%.2e\n", count, current, total, total/CROP);
    }

    printf("That's all.\n");

    return 0;
}
