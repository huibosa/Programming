#include <stdio.h>
#define SIZE 81
char * s_gets(char *, int n);

int main(void)
{
    char str[SIZE];

    s_gets(str, SIZE);

    printf("\n");
    puts(str);

    return 0;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        while (*str != '\n' && *str != '\0' && *str)
            str++;
        if (*str == '\n')
            *str = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
