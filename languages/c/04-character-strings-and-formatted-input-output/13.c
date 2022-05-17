#include <stdio.h>
int main(void)
{
    int bph2o = 212;
    int retval;

    retval = printf("%d F is water's boiling point.\n", bph2o);
    printf("The printf() function printed %d characters.\n", retval);

    return 0;
}
