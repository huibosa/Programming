// Write a program that takes two command-line arguments. The first is a
// string; the second is the name of a file. The program should then search
// the file, printing all lines containing the string. Because this task
// is line oriented rather than character oriented, use fgets() instead
// of getc(). Use the standard C library function strstr() (briefly
// described in exercise 7 of Chapter 11) to search each line for the
// string. Assume no lines are longer than 255 characters.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81

int main(int argc, char * argv[])
{
    FILE * f;
    char str[SLEN];
    char * ptr;

    if (argc != 3) {
        fputs("Usage error", stdout);
        exit(EXIT_FAILURE);
    }

    if ((f = fopen(argv[2], "r")) == NULL) {
        fputs("File open error", stdout);
        exit(EXIT_FAILURE);
    }
    
    while (fgets(str, SLEN, f))
        if (strstr(str, argv[1]) != NULL)
            fputs(str, stdout);

    fclose(f);
}
