#include <stdio.h>
int main(void)
{
    unsigned count;
    int ch;

    while ((ch = getchar()) != EOF) {
        switch (ch) {
        case '\n':
            printf("\\n    %d\n", ch);
            break;
        case '\t':
            printf("\\t    %d\n", ch);
            break;
        default:
            printf("%c    %d\n", ch, ch);
        }
    }
}
