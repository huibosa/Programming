// The new_d_array() function takes an int argument and a variable number of
// double arguments. The function returns a pointer to a block of memory
// allocated by malloc(). The int argument indicates the number of elements to
// be in the dynamic array, and the double values are used to initialize the
// elements, with the first value being assigned to the first element, and so
// on. Complete the program by providing the code for show_ array() and
// new_d_array().

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main()
{
    double * p1;
    double * p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}


double * new_d_array(int n, ...)
{
    double * temp = (double *) malloc(n * sizeof(double));

    va_list ap;
    va_start(ap, n);

    for (int i = 0; i < n; i++) {
        temp[i] = va_arg(ap, double);
    }
    va_end(ap);

    return temp;
}

void show_array(const double ar[], int n)
{
    for (int i = 0 ; i < n; i++) {
        printf("%.2lf ", ar[i]);
    }
    putchar('\n');
}
