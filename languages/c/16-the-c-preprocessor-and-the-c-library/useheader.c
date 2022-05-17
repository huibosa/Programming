// useheader.c -- use the names_st structure
#include <stdio.h>
#include "names_st.h"

// remember to link with 7.c

int main(void)
{
    names candidate;

    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this progarm!\n");

    return 0;
}
