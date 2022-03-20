// Write a program that initializes an array-of-double and then copies the
// contents of the array into three other arrays. (All four arrays should
// be declared in the main program.) To make the first copy, use a function
// with array notation. To make the second copy, use a function with pointer
// notation and pointer incrementing. Have the first two functions take as
// arguments the name of the target array, the name of the source array,
// and the number of elements to be copied. Have the third function take
// as arguments the name of the target, the name of the source, and a
// pointer to the element following the last element of the source. That
// is, the function calls would look like this, given the following
// declarations:
//
// double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
// double target1[5];
// double target2[5];
// double target3[5];
// copy_arr(target1, source, 5);
// copy_ptr(target2, source, 5);
// copy_ptrs(target3, source, source + 5);


#include <stdio.h>

void copy_arr(double target[], const double source[], int n);
void copy_ptr(double * target, const double * source, int n);
void copy_ptrs(double * target, const double * source, double * ar3);
void show_array(double * ar, int n);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    show_array(source, 5);
    show_array(target1, 5);
    show_array(target2, 5);
    show_array(target3, 5);

    return 0;
}

void copy_arr(double target[], const double source[], int n)
{
    for (int i = 0; i < n; i++)
        target[i] = source[i];
}

void copy_ptr(double * target, const double * source, int n)
{
    for (int i = 0; i < n; ++i)
        *(target + i) = *(source + i);
}

void copy_ptrs(double * target, const double * source, double * ar3)
{
    while (source < ar3) {
        *target = *source;
        target++;
        source++;
    }
}

void show_array(double * ar, int n)
{
    printf("{");
    for (int i = 0; i < n; i ++)
        printf("%.1lf, ", * (ar + i));
    printf("\b\b}\n");
}
