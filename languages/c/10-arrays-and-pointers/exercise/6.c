// Write a function that reverses the contents of an array of double
// test it in a simple program.


#include <stdio.h>
#define SIZE 5

void reverse_array(double arr[], int n);
void show_array(double * ar, int n);

int main(void)
{
    double arr[SIZE] = {1, 2, 3, 4, 5};

    reverse_array(arr, 5);
    show_array(arr, 5);
}

void reverse_array(double arr[], int n)
{
    double temp;

    for (int i = 0; i < n/2 ; i++) {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

void show_array(double * ar, int n)
{
    printf("{");
    for (int i = 0; i < n; i ++)
        printf("%.1lf, ", * (ar + i));
    printf("\b\b}\n");
}
