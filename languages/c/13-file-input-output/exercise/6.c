// Programs using command-line arguments rely on the user’s memory of
// how to use them correctly. Rewrite the program in Listing 13.2 so
// that, instead of using command-line arguments, it prompts the user
// for the required information.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 81

int main(void)
{
    FILE * in, * out;       // declare two FILE pointers
    int ch;
    char inname[LEN];
    char outname[LEN];          // storage for output filename
    int count = 0;

    printf("Enter the filename: ");
    scanf("%s", inname);

    // set up input
    if ((in = fopen(inname, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", inname);
        exit(EXIT_FAILURE);
    }

    // set up output
    strncpy(outname, inname, LEN - 5);    // copy filename
    outname[LEN - 5] = '\0';
    strcat(outname, ".red");               // append .red

    if ((out = fopen(outname, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
