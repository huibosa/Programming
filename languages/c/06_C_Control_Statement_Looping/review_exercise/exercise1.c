#include <stdio.h>
int main(void)
{
    int i;
    char j;
    char letters[26];

    for (i = 0, j = 'a'; i < 26; i++, j++)
        letters[i] = j;

    for (i = 0; i < 26; i++)
        printf("%c", letters[i]);
    printf("\n");

    return 0;
}
