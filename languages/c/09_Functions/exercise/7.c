#include <stdio.h>
#include <ctype.h>
int get_char_location(char ch);
int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        if (get_char_location(ch) != -1)
            printf("%c is a letter and has a numeric positon of %d\n",
                    ch, get_char_location(ch));
    }

    printf("Done.\n");

    return 0;
}

int get_char_location(char ch)
{
    if (isalpha(ch))
        return tolower(ch) - 'a' + 1;
    else
        return -1;
}
