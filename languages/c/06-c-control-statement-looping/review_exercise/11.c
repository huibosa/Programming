#include <stdio.h>
#define SIZE 8
int main(void)
{
    int i;
    int array[SIZE];

    printf("Enter eight integers: ");
    for (i = 0; i < SIZE; i++)
        scanf("%d", &array[i]);
    for (i = SIZE - 1; i >= 0; i--)
        printf("%8d", array[i]);
    printf("\n");

    return 0;
}
