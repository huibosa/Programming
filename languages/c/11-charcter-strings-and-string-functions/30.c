#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 81
void ToUpper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIM];
    char * find;

    puts("Please enter a line:");
    fgets(line, LIM, stdin);
    find = strchr(line, '\n');
    if (find)
        *find = '\0';
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n",
            PunctCount(line));

    return 0;
}

void ToUpper(char * str)
{
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char * str)
{
    int count = 0;

    while (*str) {
        if (ispunct(*str))
            count++;
        str++;
    }

    return count;
}
