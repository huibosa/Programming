#include <stdio.h>
#define M_TO_H 60
int main(void)
{
    int time, min, hou;

    printf("Please type a time: ");

    while(scanf("%d", &time))
    {
        hou = time / M_TO_H;
        min = time % M_TO_H;
        printf("%d minutes is %d hours and %d minutes.\n",
                time, hou, min);
        printf("Please type a time: ");
    }

    return 0;
}
