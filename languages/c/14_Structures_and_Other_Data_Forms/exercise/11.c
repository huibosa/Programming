// 11. Write a function called transform() that takes four arguments: the name
// of a source array containing type double data, the name of a target array of
// type double, an int representing the number of array elements, and the name
// of a function (or, equivalently, a pointer to a function). The transform()
// function should apply the indicated function to each element in the source
// array, placing the return value in the target array. For example, the call

// transform(source, target, 100, sin);

// would set target[0] to sin(source[0]), and so on, for 100 elements. Test the
// function in a program that calls transform() four times, using two functions
// from the math.h library and two suitable functions of your own devising as
// arguments to successive calls of the transform() function.


#include <stdio.h>
#include <math.h>

#define LIM 10
#define NUM 4

void transform(double * source, double * target,
               int number, double (*pf)(double));
void show_array(double * arr);

double half(double x);
double twice(double x);

int main(void)
{
    double target[LIM];
    double source[LIM];
    double (*pf[NUM])(double) = {half, twice, sqrt, ceil};

    for (int i = 0; i < LIM; i++)       // initialize source array
        source[i] = i * 2 + 0.5;

    for (int i = 0; i < NUM; i++)       // 
    {
        transform(source, target, LIM, pf[i]);
        show_array(target);
    }
}

void show_array(double * arr)
{
    printf("{ ");
    for (int i = 0; i < LIM; i++)
    {
        printf("%.2f, ", arr[i]);
    }
    printf("\b\b}\n");
}

void transform(double * source, double * target,
               int number, double (*pf)(double))
{
    for (int i = 0; i < number; i++)
        target[i] = (*pf)(source[i]);
}

double half(double x) {return x / 2.0;}
double twice(double x) {return x * 2.0;}
