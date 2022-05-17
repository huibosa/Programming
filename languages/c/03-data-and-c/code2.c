#include <stdio.h>
int main(void)
{
    char ch;

    printf("Please enter a charecter.\n");
    scanf("%c" &ch);
    printf("The code for %c is %d.\n", ch, ch);

    return 0;
}
