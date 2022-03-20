#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 20

void foo1(char *);
void foo2(char *);

int main(void)
{
    char arr[SIZE];

    foo2(arr);
    puts(arr);

    return 0;
}

void foo2(char *ar)
{
    char ch;
    int i = 0;

    while (isblank(ch = getchar()))
        continue;

    while ((ar[i] = getchar()) && !isblank(ar[i++]))
        continue;

    fflush(stdin);
}

void foo1(char * ar)
{
    char ch;
    bool inword = false;

    while ((ch = getchar()))
    {
        if (!inword && isspace(ch))
            continue;
        else if (inword && isspace(ch))
            break;
        else
            inword = true;
            *ar++ = ch;
    }
}

void foo2(char * ar)
{
    char ch;

    while (isspace(ch = getchar()))
        continue;

    *ar++ = ch;

    while (!isspace(ch = getchar()))
        *ar++ = ch;

    *ar = '\0';
}
