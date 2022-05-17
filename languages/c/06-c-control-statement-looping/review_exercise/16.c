#include <stdio.h>
#define SIMPLE .1
#define COMPOUND .05
#define INVESTMENT 500000
int main(void)
{
    int year;
    float Dephne_value = INVESTMENT;
    float Deirdre_value = INVESTMENT;

    year = 0;
    while (Dephne_value >= Deirdre_value) {
        Dephne_value += INVESTMENT * SIMPLE;
        Deirdre_value *=  1 + COMPOUND;
        year++;
    }
    printf("It takes %d years for Deirdre's investment to exceed\n"
           "the value of Daphne's investment.\n"
           "Deirdre has $%f now, Daphne has $%f now\n",
           year, Deirdre_value, Dephne_value);
}
