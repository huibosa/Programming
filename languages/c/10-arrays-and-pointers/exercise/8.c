// Use a copy function from Programming Exercise 2 to copy the third through
// fifth elements of a seven-element array into a three-element array. The
// function itself need not be altered; just choose the right actual
// arguments. (The actual arguments need not be an array name and array
// size. They only have to be the address of an array element and a
// number of elements to be processed.)


#include <stdio.h>

#define SIZE1 7
#define SIZE2 3

void copy_arr(int size, int target[size], const int source[size]);
void print_arr(int size, int arr[size]);

int main(void)
{
    int arr1[SIZE1] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[SIZE2];

    printf("First array: \n");
    print_arr(SIZE1, arr1);
    copy_arr(SIZE2, arr2, arr1 + 2);
    printf("Second array: \n");
    print_arr(SIZE2, arr2);

    return 0;

}

void copy_arr(int size, int target[size], const int source[size])
{
    for (int i = 0; i < size; i++)
        target[i] = source[i];
}

void print_arr(int size, int arr[size])
{
    putchar('{');
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\b\b}\n");
}
