#include <stdio.h>
#include "names.h"
#include "names.h"      // accidental second inclusion

int main(void)
{
    names winner = {"Less", "Ismoor"};
    printf("The winner is %s %s.\n", winner.first, winner.last);

    return 0;
}
