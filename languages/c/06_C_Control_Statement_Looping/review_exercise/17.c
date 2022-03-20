#include <stdio.h>
int main(void)
{
    float value = 1e6;
    int year = 0;

    while (value > 0){
        value *= 1.08;
        value -= 100000;
        year++;
    }

    printf("Years: %d\n", year);
    printf("Account value: %f\n", value);
}
