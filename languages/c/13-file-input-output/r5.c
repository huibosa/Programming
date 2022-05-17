#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 81

int main(int argc, char * argv[])
{
    FILE * fp;
    char line[LEN];
    char ch = argv[1][0];

    if (argc != 3)
        exit(EXIT_FAILURE);

    if ((fp = fopen(argv[2], "r")) == NULL)
        exit(EXIT_FAILURE);

    while (fgets(line, LEN, fp) != NULL)
    {
        if (strchr(line, ch) != NULL)
            fputs(line, stdout);
    }

    fclose(fp);

    return 0;
}
