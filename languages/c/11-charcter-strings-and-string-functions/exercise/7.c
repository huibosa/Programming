#include <stdio.h>
#include <string.h>
#define SIZE1 10
#define SIZE2 100

char * mystrncpy(char * target, const char * source, int n);

int main(void)
{
    char str1[SIZE1];
    char str2[SIZE2];

    printf("Enter some text: ");
    while (fgets(str2, SIZE2, stdin), strcmp(str2, "q\n"))
    {
        mystrncpy(str1, str2, SIZE1);
        printf("The first %d characters copied: %s\n", SIZE1, str1);
        for (int i = 0; i < SIZE1; i++)
            printf("'%d'", str1[i]);
        putchar('\n');
        printf("Enter some text (q to quit): ");
    }
    puts("Bye");

    return 0;
}

char * mystrncpy(char * target, const char * source, int n)
{
    int ct = 0;

    while (*source && ct++ < n)
    {
        *target++ = *source++;
    }

    return target;
}

char * mystrncpy(char * target, const char * source, int n)
{
    // while (*target)
        // continue;

    char * ret = target;

    while (*source && n > 0)
    {
        *target++ = *source++;
        n--;
    }

    if (n > 0)
        *target = '\0';

    return ret;
}
