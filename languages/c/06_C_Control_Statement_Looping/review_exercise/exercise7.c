#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[40];
    int i;

    printf("Enter a word");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
        printf("%c\n", str[i]);
}
