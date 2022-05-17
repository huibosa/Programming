#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SLEN 81
#define NSTR 5

char * s_get(char * str, int n);
void rmspace(char * str);

int main(void)
{
    char arr[NSTR][SLEN];
    int i = 0;

    printf("Enter %d sentence%s:\n", NSTR, (NSTR > 1) ? "s" : "");
    while (s_get(arr[i], SLEN) != NULL && arr[i++][0] != '\0')
        continue;

    puts("Here is what you entered with the spaces removed:");
    for (int i = 0; i < NSTR; i++)
    {
        rmspace(arr[i]);
        printf(arr[i]);
    }

    puts("Bye");
}

void rmspace(char * str)
{
    char *pt1, *pt2;
    pt1 = pt2 = str;

    while(*pt2)
    {
        if (*pt2 == ' ')
            pt2++;
        else
            *pt1++ = *pt2++;
    }
    *pt1 = '\0';

}
           
char * s_get(char * str, int n)
{
    char * retval = fgets(str, n, stdin);

    if (retval)
        str[strcspn(str, "\n")] = 0;

    fflush(stdin);

    return retval;
}


