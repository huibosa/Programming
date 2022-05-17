// Write a program that initializes a two-dimensional array-of-double
// and uses one of the copy functions from exercise 2 to copy it to a
// second two-dimensional array. (Because a two-dimensional array is
// an array of arrays, a one-dimensional copy function can be used with
// each subarray.)


#include <stdio.h>

#define ROWS 3
#define COLS 4

void copy_arr(int size, double * target, const double * source);
void copy_2D_array(int rows,
                   int cols,
                   double (* target)[cols],
                   const double (* source)[cols]);
void print_arr(int size, const double arr[size]);
void print_2D_arr(int rows, int cols, const double (* arr)[cols]);

int main(void)
{
    const double arr1[ROWS][COLS] = {
            {0,1,2,3},
            {4,5,6,7},
            {8,9,10,11}
    };
    double arr2[ROWS][COLS];

    copy_2D_array(ROWS, COLS, arr2, arr1);
    printf("Here is the content of the first array :\n");
    print_2D_arr(ROWS, COLS, arr1);
    printf("Here is the content of the second array :\n");
    print_2D_arr(ROWS, COLS, arr2);
}

void copy_arr(int size, double * target, const double * source)
{
    for (int i = 0; i < size; i++)
        *(target + i) = *(source + i);
}

void copy_2D_array(int rows,
                   int cols,
                   double (* target)[cols],
                   const double (* source)[cols])
{
    for (int row = 0; row < rows; row++)
        copy_arr(cols, *(target + row), *(source + row));
}

void print_arr(int size, const double * arr)
{
    putchar('{');
    for (int i = 0; i < size; i++)
        printf("%f, ", *(arr + i));
    printf("\b\b}");
}

void print_2D_arr(int rows, int cols, const double (* arr)[cols])
{
    printf("{\n");
    for (int row = 0; row < rows; row++) {
        print_arr(cols, *(arr + row));
        putchar('\n');
    }
    printf("\n}");
}
