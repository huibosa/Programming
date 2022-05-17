#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(void)
{
    bool in_word = false;
    char ch;
    unsigned letter_count = 0;
    unsigned word_count = 0;

    while ((ch = getchar()) != EOF) {
        if (isspace(ch))
            in_word = false;
        else {
            letter_count++;
            if (!in_word) {
                word_count++;
                in_word = true;
            }
        }
    }
    printf("Average number of letter perword: %d\n", letter_count / word_count);
}
