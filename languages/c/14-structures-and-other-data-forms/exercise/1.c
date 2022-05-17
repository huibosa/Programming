/* Write a function that, when given the month number, returns the total days
in the year up to and including that month. Assume that the structure
template of question 3 and an appropriate array of such structures are
declared externally. */

/* Redo Review Question 5, but make the argument the spelled-out name of the
month instead of the month number. (Don’t forget about strcmp().) Test the
function in a simple program. */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
    char name[10];
    char abbr[4];
    int days;
    int monumb;
};

const struct month months[12] = {
    {"January",   "Jan", 31, 1},
    {"February",  "Feb", 28, 2},
    {"March",     "Mar", 31, 3},
    {"April",     "Apr", 30, 4},
    {"May",       "May", 31, 5},
    {"June",      "Jun", 30, 6},
    {"July",      "Jul", 31, 7},
    {"August",    "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October",   "Oct", 31, 10},
    {"November",  "Nov", 30, 11},
    {"December",  "Dec", 31, 12}
};

int days(char *);

int main(void)
{
    char input[20];
    int daytotal;

    printf("Please enter the month abbreviation: ");
    while (scanf("%13s", input) == 1 && input[0] != 'q') {
        daytotal = days(input);

        if (daytotal > 0)
            printf("There are %d days through %s.\n", daytotal, input);
        else
            printf("%s is not a valid input.\n", input);
        printf("Next monty (q to quit): ");
    }

    return 0;
}

int days(char * str) {
    int tot = 0;

    str[0] = toupper(str[0]);

    for (int i = 1; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);

    for (int i = 0; i < 12; i++) {
        tot += months[i].days;
        if (strcmp(str, months[i].abbr) == 0) {
            return tot;
        }
    }
    return -1;
}
