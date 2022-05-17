#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'
int main(void)
{
    char c;                     // read in characeter
    char prev;                  // previous characeter read
    long n_chars = 0L;          // number of characeters
    int n_lines = 0;            // number of lines
    int n_words = 0;            // number of words
    int p_lines = 0;            // number of partial lines
    bool inword = false;        // == true if c is in a word

    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';                // used to identify complete lines

    while ((c = getchar()) != STOP)
    {
        n_chars++;               //count characeters

        if (c == '\n')
            n_lines++;
        if (!isspace(c) && !inword)
        {
            inword = true;      // starting a new word
            n_words++;          // count word
        }
        if (isspace(c) && inword)
            inword = false;     // reached end of word
        prev = c;               // save characeter value
    }

    if (prev != '\n')
        p_lines = 1;

    printf("characeter = %ld, words = %d, lines = %d, ",
            n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);

    return 0;
}
