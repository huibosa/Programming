// Write a function that returns the index of the largest value stored
// in an array-of-double.  Test the function in a simple program.


#include <stdio.h>
#define SIZE 5

int get_maxindex(double * arr, int n);

int main(void)
{
    double lar;
    double arr[SIZE] = (double [5]) {1, 7, 8, 9, 5};

    lar = get_maxindex(arr, 5);
    printf("%d\n", get_maxindex(arr, 5));

    return 0;
}

int get_maxindex(double * arr, int n)
{
    int index = 0;
    double max = *arr;

    for (int i = 0; i < n; i++)
        if (*(arr + i) > max) {
            max = *(arr + 1);
            index = i;
        }

    return index;
}
