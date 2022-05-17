#include <stdio.h>
#include <stdbool.h>
#define BASE1 17850
#define BASE2 23900
#define BASE3 29750
#define BASE4 14875
#define BASE_RATE .15
#define EXCESS_RATE .28

float tax_s(float);
float tax_hoh(float);
float tax_mj(float);
float tax_ms(float);
int make_choice(int, int);

int main(void)
{
    int choice;
    float income;

    while (true){
        printf("+-------------------------------------------------------------+\n");
        printf("|Category              Tax                                    |\n");
        printf("|-------------------------------------------------------------|\n");
        printf("|Single                15%% of first $17,850 plus 28%% of excess|\n");
        printf("|Head of Household     15%% of first $23,900 plus 28%% of excess|\n");
        printf("|Married, Joint        15%% of first $29,750 plus 28%% of excess|\n");
        printf("|Married, Separate     15%% of first $14,875 plus 28%% of excess|\n");
        printf("+-------------------------------------------------------------+\n");
        printf("Category\n"
                "1) Single                     2)Head of Household\n"
                "3) Married of Household       4)Married, Separate\n");
        printf("Enter your choice (q to quit):");
        scanf("%d", &choice);
        printf("Enter your earnings(q to quit):");
        scanf("%f", &income);

        make_choice(choice, income);
    }
}

int make_choice(int choice, int income)
{
    switch (choice) {
    case 1:
        printf("Your tax is %.2f\n", tax_s(income));
        break;
    case 2:
        printf("Your tax is %.2f\n", tax_hoh(income));
        break;
    case 3:
        printf("Your tax is %.2f\n", tax_mj(income));
        break;
    case 4:
        printf("Your tax is %.2f\n", tax_ms(income));
        break;
    default:
        printf("Please enter a interger between 1 and 5.\n");
    }
    return 0;
}
float tax_s(float income)
{
    if (income <= BASE1)
        return 0;
    else
        return BASE_RATE * BASE1 + EXCESS_RATE * (income - BASE1);
}

float tax_hoh(float income)
{
    if (income <= BASE2)
        return 0;
    else
        return BASE_RATE * BASE2 + EXCESS_RATE * (income - BASE2);
}

float tax_mj(float income)
{
    if (income <= BASE3)
        return 0;
    else
        return BASE_RATE * BASE3 + EXCESS_RATE * (income - BASE3);
}

float tax_ms(float income)
{
    if (income <= BASE4)
        return 0;
    else
        return BASE_RATE * BASE4 + EXCESS_RATE * (income - BASE4);
}

