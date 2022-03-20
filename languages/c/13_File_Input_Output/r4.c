/* Write a program that takes zero command-line arguments or one command-line
argument. If there is one argument, it is interpreted as the name of a file.
If there is no argument, the standard input (stdin) is to be used for input.
Assume that the input consists entirely of floating-point numbers. Have the
program calculate and report the arithmetic mean (the average) of the input
numbers. */

#include <stdio.h>
#include <stdlib.h>

void show_average(FILE * );
int main(int argc, char * argv[])
{
    FILE * fp;

    if (argc > 3)
        exit(EXIT_FAILURE);
    if (argc == 1)
        fp = stdin;
    else
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
            exit(EXIT_FAILURE);
    }

    show_average(fp);

    return 0;

}

void show_average(FILE * fp)
{
    double dbnum;
    double sum = 0.0;
    int count = 0;

    while (fscanf(fp, "%lf", &dbnum) != EOF)
    {
        sum += dbnum;
        count++;
    }

    printf("The average is %f", sum / count);
}
