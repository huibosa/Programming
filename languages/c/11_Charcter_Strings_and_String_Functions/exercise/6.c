#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 81

bool is_within(const char *, int);
void clean_buffer(void);

int main(void)
{
    char arr[SIZE];
    int ch;

    printf("Enter some text: ");
    while (fgets(arr, SIZE, stdin), strcmp(arr, "q\n"))
    {
        printf("Enter a character: ");
        ch = getchar();
        getchar();              // discard the newline char
        printf("%c is %s in the string.\n", ch,
                is_within(arr, ch) ? "" : " not");
        printf("Enter some text (q to quit): ");
    }
    puts("Bye");

    return 0;
}

bool is_within(const char * str, int ch)
{
    while (*str)
    {
        if (*str == ch)
            return true;
        str++;
    }

    return false;
}
