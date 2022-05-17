// Write a file copy program that prompts the user to enter the name of
// a text file to act as the source file and the name of an output file.
// The program should use the toupper() function from ctype.h to convert
// all text to uppercase as it’s written to the output file.  Use
// standard I/O and the text mode.


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define LEN 81

int main(void)
{
    char ch;
    char source[LEN];
    char target[LEN];
    FILE * fsource, * ftarget;

    puts("Please enter ther source filename");
    scanf("%s", source);
    puts("Please enter ther target filename");
    scanf("%s", target);

    if ((fsource = fopen(source, "r")) == NULL)
        exit(EXIT_FAILURE);
    if ((ftarget = fopen(target, "w")) == NULL)
        exit(EXIT_FAILURE);

    while ((ch = fgetc(fsource)) != EOF)
        fputc(toupper(ch), ftarget);

    if (fclose(fsource) != 0)
        puts("Error");
    if (fclose(ftarget) != 0)
        puts("Error");

    return 0;
}
