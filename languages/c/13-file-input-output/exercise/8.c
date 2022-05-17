// Write a program that takes as command-line arguments a character and zero
// or more filenames. If no arguments follow the character, have the program
// read the standard input. Otherwise, have it open each file in turn and
// report how many times the character appears in each file. The filename
// and the character itself should be reported along with the count.
// Include error-checking to see whether the number of arguments is correct
// and whether the files can be opened. If a file can’t be opened, have the
// program report that fact and go on to the next file.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_count(FILE *, int);

int main(int argc, char * argv[])
{
    int ch;
    FILE * fp;

    if (argc == 1)
    {
        fputs("Error", stderr);
        exit(EXIT_FAILURE);
    }

    ch = argv[1][0];

    if (argc == 2)
    {
        if (strlen(argv[1]) > 1)
        {
            puts("Must enter a character");
            exit(EXIT_FAILURE);
        }

        fp = stdin;
        printf("There are %d '%c' in standard input.\n",
                char_count(fp, ch), ch);
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                printf("File: %s open error", argv[i]);
                continue;
            }
            printf("%d '%c' in file: %s\n", char_count(fp, ch), ch, argv[i]);

            fclose(fp);
        }
    }

    return 0;
}

int char_count(FILE * fp, int target_ch)
{
    int count = 0;
    int ch;

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == target_ch)
            count++;
    }

    return count;
}
