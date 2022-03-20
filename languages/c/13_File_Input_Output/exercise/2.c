// Write a file-copy program that takes the original filename and
// the copy file from the command line. Use standard I/O and the
// binary mode, if possible.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    char byte;
    FILE * fsource, * ftarget;

    if (argc != 3)
    {
        puts("Error");
        exit(EXIT_FAILURE);
    }
    if ((ftarget = fopen(argv[1], "wb")) == NULL)
    {
        puts("Error");
        exit(EXIT_FAILURE);
    }
    if ((fsource = fopen(argv[2], "r")) == NULL)
    {
        puts("Error");
        exit(EXIT_FAILURE);
    }

    while ((byte = getc(fsource)) != EOF)
        putc(byte, ftarget);

    if (fclose(fsource) != 0)
        puts("Error");
    if (fclose(ftarget) != 0)
        puts("Error");

    return 0;
}
