// Modify Listing 13.1 so that it solicits the user to enter the
// filename and reads the user’s response instead of using command-line
// arguments.


#include <stdio.h>
#include <stdlib.h>

#define LEN 81

int main(void)
{
    int ch;
    FILE * fp;
    char filename[LEN];
    unsigned long count = 0;

    printf("Please enter the filename: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "rb")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);

    return 0;
}
