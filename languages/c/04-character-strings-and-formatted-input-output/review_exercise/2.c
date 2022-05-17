#include <stdio.h>
int main(void)
{
    char first[20];

    printf("What's is your first name?");
    scanf("%s", first);
    printf("Your first name is \"%20s\"\n", first);

    return 0;
}
