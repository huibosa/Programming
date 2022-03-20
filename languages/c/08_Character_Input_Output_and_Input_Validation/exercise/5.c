#include <stdio.h>
#include <stdbool.h>

int guess_number(int choice, int guess);

int main(void)
{
    int guess = 50;
    int choice;
    int low_limit = 0;
    int up_limit = 100;

    while (true) {
        printf("Is it %d?\n"
                "0) Yes    1) High    2) Low\n"
                "Your choice: ", guess);
        scanf("%d", &choice);

        if (choice == 0)
            break;
        else if (choice == 1)
            up_limit = guess;
        else
            low_limit = guess;
        guess = (up_limit + low_limit) / 2;
    }
    printf("Done.\n");
}
