#include <stdio.h>
int main(void)
{
    int row, col;
    char ch;

    for (row = 1; row <= 6; row++)
    {
        for (col = 1, ch = 'F'; col <= row; col++, ch--)
            printf("%c", ch);
        printf("\n");
    }
}
