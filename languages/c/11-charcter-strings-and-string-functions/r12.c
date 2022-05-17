#include <stdio.h>
char * foo(char *);

int main(void)
{
    char str[81] = "hel lo";

    char * flag = foo(str);

    puts(flag);
    
}

char * foo(char * str)
{
    while (*str)
    {
        if (*str == ' ')
            return str;
        str++;
    }

    return NULL;
}


char * foo2(char * str)
{
    while (*str != ' ' && *str != '\0')
        str++;
    if (*str == '\0')
        return NULL;
    else
        return str;
}

char * foo3(const char * str)
{
    while (*str != ' ' && *str != '\0')
        str++;
    if (*str == '\0')
        return NULL;
    else
        return (char *) str;
}
