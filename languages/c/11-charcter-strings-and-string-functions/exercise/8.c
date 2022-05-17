#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 81

const char * string_in(const char * mother, char * child);

int main(void)
{
    char ar1[SIZE];
    char ar2[SIZE];
    const char * ptr;

    puts("Enter a string:");
    while (fgets(ar1, SIZE, stdin)[0] != '\n')
    {
        puts("Enter a string to search:");

        fgets(ar2, SIZE, stdin);

        ar2[strlen(ar2) - 1] = '\0';

        if ((ptr = string_in(ar1, ar2)))
        {
            puts("End of line beginning from your string found:");
            fputs(ptr, stdout);
        }
        else
            puts("String not found.");

        puts("Enter a new string (empty line to quit):");
    }

    return 0;
}

const char * string_in(const char * mother, char * child)
{
    while (*mother)
    {
        if (!strncmp(mother, child, strlen(child)))
            return (char *) mother;
        mother++;
    }

    return NULL;
}
