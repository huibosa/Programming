#include <stdio.h>
#include <stdbool.h>
bool bad_limits(long begin, long end,
                long low, long high)
{
    bool not_good = false;

    if (begin > end) {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low) {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high) {
        printf("Values must be %ld or less.\n", high);
        not_good = true;
    }

    return 0;

}
