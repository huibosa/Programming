#include <stdio.h>
#define SIZE 4

int main(void)
{
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;

    printf("value1 = %d, value2 = %d\n", value1, value2);
    for (int i = 0; i < SIZE; i++)
        arr[i] = 2 * i + i;

    for (int i = 0; i < SIZE; i++)
        printf("%2d  %d\n", i , arr[i]);
    printf("value1 = %d, value2 = %d\n", value1, value2);
    printf("address of arr[-1]: %p\n", &arr[-1]);
    printf("address of arr[4]:  %p\n", &arr[4]);
    printf("address of value1:  %p\n", &value1);
    printf("address of value2:  %p\n", &value2);

    return 0;
}
