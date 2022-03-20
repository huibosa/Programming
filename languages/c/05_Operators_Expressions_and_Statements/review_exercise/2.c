#include <stdio.h>
#define M_TO_H 60
int main(void)
{
    int num, larger_num;

    printf("Please type an integer: ");
    scanf("%d", &num);

    larger_num = num + 10;

    while (num <= larger_num) 
    {
        printf("%d\n", num++);
    }
    return 0;
}
