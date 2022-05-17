#include <stdio.h>
#include <string.h>
int main(void)
{
    char first[20];
    char last[20];

    printf("What's is your name?");
    scanf("%s%s", first, last);
    printf("%s %s\n", first, last);
    printf("%*ld %*ld\n", strlen(first), strlen(first),
            strlen(last), strlen(last));
    printf("%s %s\n", first, last);
    printf("%-*ld %-*ld\n", strlen(first), strlen(first),
            strlen(last), strlen(last));

    return 0;
}
