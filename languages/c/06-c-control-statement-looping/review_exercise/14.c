#include <stdio.h>
#define SIZE 8
int main(void)
{
    int array1[SIZE];
    int array2[SIZE];

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &array1[i]);

    array2[0] = array1[0];
    for (int i = 1; i < SIZE; i++)
        array2[i] = array2[i - 1] + array1[i];

    for (int i = 0; i < SIZE; i++)
        printf("%d ", array1[i]);
    printf("\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array2[i]);
    printf("\n");

    return 0;
}
