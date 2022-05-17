// Write a program that prompts the user to enter three sets of five
// double numbers each.  (You may assume the user responds correctly
// and doesn’t enter non-numeric data.) The program should accomplish
// all of the following:

// a. Store the information in a 3×5 array.
// b. Compute the average of each set of five values.
// c. Compute the average of all the values.
// d. Determine the largest value of the 15 values.
// e. Report the results.

// Each major task should be handled by a separate function using the
// traditional C approach to handling arrays. Accomplish task “b” by
// using a function that computes and returns the average of a
// one-dimensional array; use a loop to call this function three times.
// The other tasks should take the entire array as an argument, and
// the functions performing tasks “c” and “d” should return the answer
// to the calling program.


#include <stdio.h>

#define ROWS 3
#define COLS 5

void get_array(int rows, int cols, double arr[rows][cols]);
void print_set_average(int rows, int cols, const double arr[rows][cols]);
double get_array_average(int rows, int cols, const double arr[rows][cols]);
double get_largest(int rows, int cols, const double arr[rows][cols]);

int main(void)
{
    double num;
    double arr[ROWS][COLS];
    double * set1_average, * set2_average, * set3_average;
    double array_average;
    double largest;

    get_array(ROWS, COLS, arr);
    print_set_average(ROWS, COLS, arr);

    array_average = get_array_average(ROWS, COLS, arr);
    largest = get_largest(ROWS, COLS, arr);

    printf("Array average: %f\n", array_average);
    printf("Largest: %f\n", largest);

    return 0;
}

void get_array(int rows, int cols, double arr[rows][cols])
{
    double num;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            scanf("%lf", &num);
            arr[row][col] = num;
        }
    }
}

void print_set_average(int rows, int cols, const double arr[rows][cols])
{
    double subtotal;

    for (int row = 0; row < rows; row++) {
        subtotal = 0;
        for (int col = 0; col < cols; col++) {
            subtotal += arr[row][col];
        }
        printf("Set%d average: %f\n", row + 1, subtotal / cols);
    }
}

double get_array_average(int rows, int cols, const double arr[rows][cols])
{
    double total = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            total += arr[row][col];
        }
    }

    return total / (rows * cols);
}

double get_largest(int rows, int cols, const double arr[rows][cols])
{
    double MAX = **arr;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (arr[row][col] > MAX) {
                MAX = arr[row][col];
            }
        }
    }

    return MAX;
}
