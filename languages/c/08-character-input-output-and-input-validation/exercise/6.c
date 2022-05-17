#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(vid)
{
    char ch;

    printf("Please enter some text: ");
    ch = get_first();
    printf("The first non-whitespace character you entered is %c.\n", ch);

    return 0;
}

char get_first(void)
{
    char ch;

    while (isspace (ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    return ch;
}
