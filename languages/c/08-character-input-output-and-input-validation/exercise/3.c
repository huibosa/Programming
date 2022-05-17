#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int ch;
    unsigned lower_count = 0;
    unsigned upper_count = 0;
    unsigned other_count = 0;

    while ((ch = getchar()) != EOF) {
        if (islower(ch))
            lower_count++;
        else if (isupper(ch))
            upper_count++;
        else
            other_count++;
    }
    printf("Lower letters: %u\n", lower_count);
    printf("Upper letters: %u\n", upper_count);
    printf("Other letters: %u\n", other_count);
}
