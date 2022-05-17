#include <stdio.h>
#define CODE_G 74
int main(void)
{
    int asc = 96;

    while (asc++ < 103) 
    {
        printf("%5c", asc);
    }
    printf("\n");

    return 0;
}
