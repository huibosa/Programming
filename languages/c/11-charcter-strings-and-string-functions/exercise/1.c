// Design and test a function that fetches the next n characters from input
// (including blanks, tabs, and newlines), storing the results in an array
// whose address is passed as an argument.


#include <stdio.h>
#define LEN 5
void getnchar(int n, char [n]);

int main(void)
{
    char arr[LEN];

    getnchar(LEN, arr);
    puts(arr);

    return 0;
}

void getnchar(int n, char ar[n])
{

    for (int i = 0; i < n; i++)
        *ar++ = getchar();
}
