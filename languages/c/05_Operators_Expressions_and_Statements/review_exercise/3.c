#include <stdio.h>
int main(void)
{
    const int D_TO_W = 7;
    int total_day;
    int week;
    int day;

    printf("Please enter the number of days: ");

    while (scanf("%d", &total_day))
    {
        week = total_day / D_TO_W;
        day = total_day % D_TO_W;

        printf("%d days are %d week(s), %d days\n", total_day, week, day);
        printf("Please enter the number of days: ");
    }

    return 0;
}
