#include <stdio.h>
int main(void)
{
    char old_ch = 'a';
    char new_ch;
    int ei_count = 0;

    while ((new_ch = getchar()) != '#') {
        if (old_ch == 'e' && new_ch == 'i')
            ei_count++;
        old_ch = new_ch;
    }
    printf("The 'ei' has occured %d time",
            ei_count, (ei_count == 0) ? ".": "s.");
}
