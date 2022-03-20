#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int my_atoi(const char *);

int main(void)
{
    char str[20];

    printf("Enter an integer: ");
    fgets(str, 20, stdin);
    str[strcspn(str, "\n")] = 0;
    fflush(stdin);

    printf("Here is your integer doubleed: %d\n", my_atoi(str) * 2);

    return 0;
}

int my_atoi(const char *str)
{
    int nb_digits = 0;
    const char * start_number;
    int retval = 0;

    while (*str && isspace(*str))
        str++;

    if (!isdigit(*str))
        return 0;
    else
    {
        start_number = str;
        while (*str && isdigit(*str))
        {
            nb_digits++;
            str++;
        }
        for (int i = nb_digits - 1; i >= 0; i--)
            retval += (*start_number++ - '0') * pow(10, i);
    }
    return retval;
}
