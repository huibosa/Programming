#include <stdio.h>
int main(void)
{
    int code;
    char ch;

    printf("Please type an ASCII: ");
    scanf("%d", &code);

    ch = code;
    printf("%c\n", ch);
}
