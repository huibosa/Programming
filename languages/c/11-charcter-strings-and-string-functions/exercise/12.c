#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define LIM 81

char * s_gets(char *, int);

int main(void)
{
    char str[LIM];
    char *ptr;
    bool in_word = false;
    int upper, lower, punct, digits, words;
    upper = lower = punct = digits = words = 0;

    puts("Enter some text (EOF to finish):");

    while (s_gets(str, LIM))
    {
        ptr = str;

        while (*ptr)
        {
            if (isalpha(*ptr) && !in_word)
            {
                in_word = true;
                words++;
            }
            else if (isspace(*ptr))
                in_word = false;
            else if (isupper(*ptr))
                upper++;
            else if (islower(*ptr++))
                lower++;
            else if (ispunct(*ptr++))
                punct++;
            else if (isdigit(*ptr++))
                digits++;
            ptr++;
        }
    }
    printf("Words count: %d\n"
           "Lowercase letters: %d\n"
           "Uppercase letters: %d\n"
           "Punctuation characters: %d\n"
           "Number of digits: %d\n",
           words, lower, upper, punct, digits);
    puts("Bye");
    return 0;
}

char * s_gets(char * str, int n)
{
    char * retval = fgets(str, n, stdin);

    if (retval)
        str[strcspn(str, "\n")] = 0;

    fflush(stdin);

    return retval;
}


