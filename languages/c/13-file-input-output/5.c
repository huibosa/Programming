#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE * source, FILE * dest);
char * s_get(char * st, int n);

int main(void) {
    FILE * fa, * fs;        // fa for append file, fs for source file
    int files = 0;          // number of files appended
    char file_app[SLEN];    // name of append file
    char file_src[SLEN];    // name of source file
    int ch;

    puts("Enter name of the destination file:");
    s_get(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOLBF, BUFSIZE) != 0) {
        fputs("Can't craete output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of the first source file (empty line to quit):");
    while (s_get(file_src, SLEN) && file_src[0] != '\0') {
        if (strcmp(file_src, file_app) == 0) {
            fputs("Can't append file to itself\n", stderr);
        }
        else if ((fs = fopen(file_src, "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", file_src);
        }
        else {
            if (setvbuf(fs, NULL, _IOLBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
        
            append(fs, fa);

            if (ferror(fs) != 0) {
                fprintf(stderr, "Error in writing file %s", file_src);
            }
            if (ferror(fa) != 0) {
                fprintf(stderr, "Error in writing file %s", file_app);
            }

            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
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

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest);
    }
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
