// Modify the rain program in Listing 10.7 so that it does the
// calculations using pointers instead of subscripts. (You still
// have to declare and initialize the array.)


/* rain.month  -- finds yearly totals, yearly average, and monthly
                  average for several years of rainfall data */
#include <stdio.h>
#define MONTHS 12    // number of months in a year
#define YEARS   5    // number of years of data

float show_years(const float ar[][MONTHS], int years);
void show_months(const float ar[][MONTHS], int years);

int main(void)
{
    float total;
    
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
 
    printf(" YEAR    RAINFALL  (inches)\n");
 
    total = show_years(rain, YEARS);
 
    printf("\nThe yearly average is %.1f inches.\n\n",
            total/YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");
 
    show_months(rain, YEARS);
 
    return 0;
}

float show_years(const float ar[][MONTHS], int years)
{
    float total = 0;
    float subtotal;

    for (int year = 0; year < years; year++) {
        subtotal = 0;
        for (int month = 0; month < MONTHS; month++)
            subtotal += *(*(ar + year) + month);
        printf("%5d%15.1f\n", year + 2014, subtotal);
        total += subtotal;
    }

    return total;
}

void show_months(const float ar[][MONTHS], int years)
{
    float subtotal;

    for (int month = 0; month < MONTHS; month++) {
        subtotal = 0;
        for (int year = 0; year < years; year++)
            subtotal += *(*(ar + year) + month);
        printf(" %.1f ", subtotal / years);
    }

    printf("\n");
}
