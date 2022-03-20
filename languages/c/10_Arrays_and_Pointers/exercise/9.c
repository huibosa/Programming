// Write a program that initializes a two-dimensional 3×5 array-of-double
// and uses a VLA- based function to copy it to a second two-dimensional
// array. Also provide a VLA-based function to display the contents of
// the two arrays. The two functions should be capable, in general, of
// processing arbitrary N×M arrays. (If you don’t have access to a
// VLA-capable compiler, use the traditional C approach of functions
// that can process an N×5 array).


#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy_arr(int rows,
              int cols,
              double target[rows][cols],
              const double source[rows][cols]);
void show_arr(int rows, int cols, const double arr[rows][cols]);

int main(void)
{
    double arr1[ROWS][COLS] = {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15}
    };
    double arr2[3][5];

    printf("Array1:\n");
    show_arr(ROWS, COLS, arr1);
    copy_arr(ROWS, COLS, arr2, arr1);
    printf("Array2:\n");
    show_arr(ROWS, COLS, arr2);


}

void copy_arr(int rows,
              int cols,
              double target[rows][cols],
              const double source[rows][cols])
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            target[row][col] = source[row][col];
}

void show_arr(int rows, int cols, const double arr[rows][cols])
{
    printf("{\n");
    for (int row = 0; row < rows; row++) {
        printf("\t{");
        for (int col = 0; col < cols; col++)
            printf("%.0f, ", arr[row][col]);
        printf("\b\b},\n");
    }
    printf("\b\b\n}\n");
}
