// Write a program that implements a menu by using an array of pointers to
// functions. For instance, choosing `a` from the menu would activate the
// function pointed to by the first element of the array.


#include <stdio.h>
#include <math.h>   // for sqrt()

extern double sqrt(double x);
double twice(double x);
double half(double x);
double thrice(double x);
void show_menu(void);

#define NUM 4

int main(void)
{
    double (*pf[NUM])(double) = {twice, half, thrice, sqrt};
    double val;
    double ans;
    int sel;

    printf("Enter the number (negative to quit): ");
    while (scanf("%lf", &val) == 1 && val > 0)
    {
        show_menu();
        while (scanf("%d", &sel) == 1 && sel >= 0 && sel <= 3)
        {
            ans = (*pf[sel])(val);  // first notation
            printf("Answer: %f\n", ans);
            ans = pf[sel](val);     // second notation
            printf("Answer: %f\n", ans);
            show_menu();
        }
        printf("Enter next number (negative to quit): ");
    }

    return 0;
}

void show_menu(void)
{
    puts("Enter one of the following choices:");
    puts("0) double the value        1) halve the value");
    puts("2) triple the value        3) squareroot the value");
    puts("4) next number");
}

double twice(double x) {return 2.0 * x;}
double half(double x) {return x / 2.0;}
double thrice(double x) {return 3.0 * x;}
