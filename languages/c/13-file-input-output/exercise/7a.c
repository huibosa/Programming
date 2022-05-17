// Write a program that opens two files. You can obtain the filenames
// either by using command-line arguments or by soliciting the user
// to enter them.

// a. Have the program print line 1 of the first file, line 1 of the
// second file, line 2 of the first file, line 2 of the second file,
// and so on, until the last line of the longer file (in terms of
// lines) is printed.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
    FILE * fp1, * fp2;
    int ch1, ch2;

    if (argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s for read.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open %s for read.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    ch1 = getc(fp1);
    ch2 = getc(fp2);

    while (ch1 != EOF || ch2 != EOF)
    {
        while (ch1 != EOF && ch1 != '\n')
        {
            putc(ch1, stdout);
            ch1 = getc(fp1);
        }
        if (ch1 != EOF)
        {
            putchar('\n');
            ch1 = getc(fp1);
        }
        while (ch2 != EOF && ch2 != '\n')
        {
            putc(ch2, stdout);
            ch2 = getc(fp2);
        }
        if (ch2 != EOF)
        {
            putchar('\n');
            ch2 = getc(fp2);
        }
    }

    if (fclose(fp1) != 0)
        printf("Could not close file %s\n", argv[1]);
    if (fclose(fp2) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}
