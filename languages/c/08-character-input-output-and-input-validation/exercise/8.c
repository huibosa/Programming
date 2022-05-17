#include <stdio.h>
#include <stdbool.h>
float get_number(void);
int main(void)
{
    char choice;
    float first, second;

    while (true){
        printf("Enter the operation of your choice:\n"
                "a. add           s. subtract\n"
                "m. multiply      d. divide\n"
                "q. quit\n");

        choice = getchar();
        if (choice == 'q')
            break;

        while (getchar() != '\n')
            continue;

        switch (choice) {
            case 'a':
                printf("Enter the first number: ");
                first = get_number();
                printf("Enter the second number: ");
                second = get_number();
                printf("%.1f + %.1f = %.1f\n", first, second, first + second);
                break;
            case 's':
                printf("Enter the first number: ");
                first = get_number();
                printf("Enter the second number: ");
                second = get_number();
                printf("%.1f - %.1f = %.1f\n", first, second, first - second);
                break;
            case 'm':
                printf("Enter the first number: ");
                first = get_number();
                printf("Enter the second number: ");
                second = get_number();
                printf("%.1f * %.1f = %.1f\n", first, second, first * second);
                break;
            case 'd':
                printf("Enter the first number: ");
                first = get_number();
                printf("Enter the second number: ");
                second = get_number();
                printf("%.1f / %.1f = %.1f\n", first, second, first / second);
                break;
            default:
                printf("Please enter a, s, m, d, or q.\n");
        }
    }

    return 0;
}

float get_number(void)
{
    float num;
    char ch;

    while (scanf("%f", &num) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n"
                "Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    return num;
}

