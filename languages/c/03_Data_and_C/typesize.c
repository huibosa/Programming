// typesize.c -- prints out type sizes 
#include <stdio.h>
int main(void)
{
    // c99 provides a %zd specifier for sizes 
    printf("Type short has a size of %zd bits.\n", sizeof(short) * 8);
    printf("Type int has a size of %zd bits.\n", sizeof(int) * 8);
    printf("Type char has a size of %zd bits.\n", sizeof(char) * 8);
    printf("Type long has a size of %zd bits.\n", sizeof(long) * 8);
    printf("Type long long has a size of %zd bits.\n", sizeof(long long) * 8);
    printf("Type double has a size of %zd bits.\n", sizeof(double) * 8);
    printf("Type long double has a size of %zd bits.\n", sizeof(long double) * 8);

    return 0;
}
