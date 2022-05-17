#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int lc = 0;
    int uc = 0;
    int oc = 0;

    while ((ch = getchar()) != '#') {
        if (islower(ch))
            lc++;
        else if (isupper(ch))
            uc++;
        else
            oc++;
    }
    printf("%d lowercase, %d uppercase, %d other", lc, uc, oc);
    return 0;
}
