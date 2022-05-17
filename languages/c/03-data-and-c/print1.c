#include <stdio.h>
int main(void)
{
    int ten = 10;
    int two = 2;

    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two );

    printf("Doinng it wrong: ");
    printf("%d minus %d is %d\n", ten );     // forgot 2 arguments

    return 0;
}
