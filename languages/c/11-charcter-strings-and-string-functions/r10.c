#include <stdio.h>
#include <string.h>
char * s_gets(char * str, int n);

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(str, n, stdin);

    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
