#include <stdio.h>
#define SIZE 20
int main(void)
{
    int i;
    int array[SIZE];
    array[0] = 2;

    for (i = 1; i < SIZE; i++)
        array[i] = array[i - 1] * 2;

    i = 0;
    do 
        printf("%d\n", array[i++]);
    while (i < SIZE);

    return 0;
}
