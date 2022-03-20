// Modify the program in Listing 13.5 so that it uses a command-line
// interface instead of an interactive interface.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE * source, FILE * dest);
char * s_get(char * st, int n);

int main(int argc, char * argv[])
{
    FILE * fa, * fs;        // fa for append file, fs for source file
    int files = 0;          // number of files appended
    int ch;

    if (argc < 3)
    {
        printf("Usage: %s destination_file"
               "source_file1 source_file2 ...", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOLBF, BUFSIZE) != 0)
    {
        fputs("Can't craete output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOLBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }

            append(fs, fa);

            if (ferror(fs) != 0)
                fprintf(stderr, "Error in writing file %s", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s", argv[1]);

            fclose(fs);
            files++;
            printf("File %s appended.\n", argv[1]);
        }
    }

    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];              // allocate once

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char * s_get(char * st, int n)
{
    char * retval;
    char * find;

    retval = fgets(st, n, stdin);
    if (retval)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return retval;
}
