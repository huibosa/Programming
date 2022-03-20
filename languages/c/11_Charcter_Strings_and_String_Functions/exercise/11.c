#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LEN 100

char prompt_menu_choice(void);
void print_strings(int LIM, const char [LIM][LEN]);
void print_ASCII_collating_sequence(int LIM, const char [LIM][LEN]);
void print_in_ascending_order(int LIM, const char [LIM][LEN]);
void print_in_ascending_first_word_length(int LIM, const char [LIM][LEN]);
size_t size_word(const char *);

int main(void)
{
    char strs[10][LEN];
    int LIM = 0;
    char menu_choice;
    bool want_to_quit = false;

    puts("Reading 10 strings or until EOF:");
    while (LIM < 10 && fgets(strs[LIM], LEN, stdin))
        ++LIM;

    while (!want_to_quit)
    {
        menu_choice = prompt_menu_choice();
        switch (menu_choice)
        {
            case 'q':
                want_to_quit = true;
                break;
            case 'a':
                print_strings(LIM, strs);
                break;
            case 'b':
                print_ASCII_collating_sequence(LIM, strs);
                break;
            case 'c':
                print_in_ascending_order(LIM, strs);
                break;
            case 'd':
                print_in_ascending_first_word_length(LIM, strs);
                break;
            default:
                puts("Action requested not found.");
        }
    }
    puts("Bye");

    return 0;
}

char prompt_menu_choice(void)
{
    char ch;

    printf("Enter the letter corresponding to the desired action:\n"
           "a) print strings                   b) print ASCII values\n"
           "c) print sorted by length          d) print by length of first word\n"
           "q) quit\n"
           "intput: ");
    scanf("%c", &ch);

    while (getchar() != '\n')
        continue;

    return ch;
}

void print_strings(int LIM, const char strs[LIM][LEN])
{
    for (int i = 0; i < LIM; i++)
        fputs(strs[i], stdout);
}

void print_ASCII_collating_sequence(int LIM, const char strs[LIM][LEN])
{
    const char * ptr;

    for (int i = 0; i < LIM; i++)
    {
        ptr = strs[i];
        while (*ptr)
            printf("%d ", *ptr++);
        printf("\b\n");
    }
}

void print_in_ascending_order(int LIM, const char strs[LIM][LEN])
{
    const char * ptr[LIM];
    const char * least = ptr[0];

    // copy contents of the original strings
    for (int i = 0; i < LIM; i++)
        ptr[i] = strs[i];

    for (int i = 0; i < LIM; i++)
    {
        for (int j = i; j < LIM; j++)
            if (strlen(ptr[j]) < strlen(ptr[i]))
            {
                least = ptr[j];
            }
    }
}
