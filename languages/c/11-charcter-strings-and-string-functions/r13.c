#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "GRANT"
#define SIZE 40
char * s_get(char * str, int n);
void str_toupper(char * str);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_get(try, SIZE);

    str_toupper(try);
    while (strcmp(try, ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_get(try, SIZE);
        str_toupper(try);
    }
    puts("That's right!");

    return 0;
}

void str_toupper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

char * s_get(char * str, int n)
{
    char * ret_val;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        while (*str != '\n' && *str != '\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
