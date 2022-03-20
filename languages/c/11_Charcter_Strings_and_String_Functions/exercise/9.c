#include <stdio.h>
#include <string.h>
#define SIZE 81

void strrev(char * str);

int main(void)
{
    char str[SIZE];

    printf("Please enter a string (q to quit):");
    while (fgets(str, SIZE, stdin) && strcmp(str, "q\n"))
    {
        int i = 0;

        // get rid of newline
        while (str[++i] != '\n')
            continue;
        str[i] = '\0';

        // clean buffer
        while (getchar() != '\n')
            continue;

        strrev(str);

        printf("The reversed string is:");
        fputs(str, stdout);
        putchar('\n');

        printf("Please enter a string (q to quit):");
    }
    puts("Bye");

    return 0;
}

void strrev(char * str)
{
    int len;
    char temp;

    len = strlen(str);

    for (int i = 0; i < len/2; i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
