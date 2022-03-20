#include <stdio.h>
int main(void)
{
    char ch;

    while ((ch = getchar()) != '#') {
        if (ch == ',') {
            ch = '!';
            putchar(ch);
        }
        else if (ch == '!') {
            putchar(ch);
            putchar(ch);
        }
        else
            putchar(ch);
    }

    return 0;
}
