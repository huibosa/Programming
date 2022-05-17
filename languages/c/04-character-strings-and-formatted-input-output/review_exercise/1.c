#include <stdio.h>
int main(void)
{
    char first[20];
    char last[20];

    printf("What's is your name?");
    scanf("%s%s", first, last);
    printf("Your name is %s %s", last, first);

    return 0;
}
