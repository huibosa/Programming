// Write a function that returns the difference between the largest
// and smallest elements of an array-of-double. Test the function in
// a simple program.  

#include <stdio.h>
double get_difference(double arr[], double n);

int main(void)
{
    double max;
    double arr[] = {1, 7, 8, 9, 5};

    max = get_difference(arr, 5);
    printf("%lf\n", get_difference(arr, 5));

    return 0;
}

double get_difference(double * arr, double n)
{
    double max, min;

    max = min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    return max - min;
}
