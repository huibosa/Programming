// Modify and test the function in exercise 1 so that it stops after n
// characters or after the first blank, tab, or newline, whichever comes first.
// (Don’t just use scanf() .)


#include <stdio.h>
#include <ctype.h>
#define SIZE 5

void foo(int n, char [n]);

int main(void)
{
    char arr[SIZE];

    foo(SIZE, arr);
    puts(arr);

    return 0;
}

void foo(int n, char ar[n])
{
    int i = 0;

    while ((ar[i] = getchar()) && !isblank(ar[i++]) && i < n)
        continue;
}
