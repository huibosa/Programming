#include <stdio.h>
int main(void)
{
    char ch;

    while ((ch = getchar()) != '#') {
        switch (ch) {
        case ',':
            ch = '!';
            putchar(ch);
            break;
        case '!':
            putchar(ch);
            putchar(ch);
            break;
        default:
            putchar(ch);
        }
    }
}
