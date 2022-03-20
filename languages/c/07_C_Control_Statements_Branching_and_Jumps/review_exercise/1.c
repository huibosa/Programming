#include <stdio.h>
int main(void)
{
    char ch;
    int sc = 0;
    int nc = 0;
    int oc = 0;

    while ((ch = getchar()) != '#') {
        switch (ch) {
        case ' ':
            sc++;
            break;
        case '\n':
            nc++;
            break;
        default:
            oc++;
        }
    }
    printf("space count: %d\n", sc);
    printf("newline count: %d\n", nc);
    printf("other count: %d\n", oc);

    return 0;
}
