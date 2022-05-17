#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 5

void foo1(char *, int);
void foo2(char *, int);

int main(void)
{
    char arr[SIZE];
    char *str = arr;

    foo1(str, SIZE);
    puts(arr);

    return 0;
}

void foo1(char * ar, int n)
{
    char ch;
    bool inword = false;
    int count = 0;

    while ((ch = getchar()) && count < n)
    {
        if (!inword && isspace(ch))
            continue;
        else if (inword && isspace(ch))
            break;
        else
            inword = true;
            *ar++ = ch;
            count++;
    }

    *ar = '\0';
}

void foo2(char * ar, int n)
{
    char ch;
    int i;

    while (isspace(ch = getchar()))
        continue;

    *ar++ = ch;

    while (!isspace(ch = getchar()) && i++ < n)
        *ar++ = ch;

    *ar = '\0';
}
