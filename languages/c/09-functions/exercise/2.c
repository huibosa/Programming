#include <stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
    char ch;
    int i, j;

    printf("Enter a character and two integers: ");
    while(scanf("%c%d%d", &ch, &i, &j) != 3) {
        while (getchar() != '\n')
            continue;
        printf("Wrong input.\n"
               "Input should like: k 3 7\n"
               "Try again: ");
    }
    chline(ch, i, j);
    printf("\nBye.\n");
}

void chline(char ch, int i, int j)
{
    for (int k = 0; k < i; k++)
        printf(" ");
    for (int k = i; k <= j; k++)
        printf("%c", ch);
}
