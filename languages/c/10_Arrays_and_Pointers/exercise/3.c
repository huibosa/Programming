// Write a function that returns the largest value stored in an array-of-int.
// Test the function in a simple program.


#include <stdio.h>
#define SIZE 5
int get_largest(int * arr, int n);

int main(void)
{
    int lar;
    int arr[SIZE] = (int [5]) {1, 2, 3, 4, 5};

    lar = get_largest(arr, 5);
    printf("%d\n", lar);

    return 0;
}

int get_largest(int * arr, int n)
{
    int MAX = *arr;

    for (int i = 0; i < n; i ++)
        if (*(arr + i) > MAX)
            MAX = *(arr + i);

    return MAX;
}
