#include <stdio.h>
#define DUNBAR 150
int main(void)
{
    int count = 5;

    for (int i = 1; count <= DUNBAR; ++i){
        count -= i;
        count *= 2;
        printf("Week: %d\tCount: %d.\n", i, count);
    }

    return 0;
}
