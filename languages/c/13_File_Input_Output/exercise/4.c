// Write a program that sequentially displays onscreen all the files listed
// in the command line. Use argc to control a loop.


#include <stdio.h>

int main(int argc, char * argv[])
{
    FILE * fp;
    char ch;

    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");

        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);
    }

    fclose(fp);

    return 0;
}
