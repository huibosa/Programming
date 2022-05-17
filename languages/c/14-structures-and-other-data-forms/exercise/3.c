// Revise the book-listing program in Listing 14.2 so that it prints the book
// descriptions in the order entered, then alphabetized by title, and then in
// order of increased value.

#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100       // max number of books


struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char *, int);
void print_alpha_order(struct book *, int);
void print_val_order(struct book *, int);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;

    puts("Please enter the book title.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS &&
           s_gets(library[count].title, MAXTITL) != NULL &&
           library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);

        puts("Now enter the value.");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n')
            continue;

        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    if (count > 0)
    {
        puts("Here is the list of you books in the order entered:");
        for (int i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n", library[i].title,
                                        library[i].author,
                                        library[i].value);
        puts("Here is the list of you books in the order of"
             " alphabetized by title:");
        print_alpha_order(library, count);

        puts("Here is the list of you books in the order of increased value:");
        print_val_order(library, count);
    }
    else
        puts("No books? Too bad.");

    return 0;
}

void print_alpha_order(struct book library[], int n)
{
    struct book tmp[n];
    struct book temp;

    for (int i = 0; i < n; i++)
        tmp[i] = library[i];

    for (int i = 0; i < n-1; i++)
        for (int k = i+1; k < n; k++)
            if (strcmp(tmp[i].title, tmp[k].title) > 0)
            {
                temp = tmp[i];
                tmp[i] = tmp[k];
                tmp[k] = temp;
            }

    for (int i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", tmp[i].title, tmp[i].author, tmp[i].value);
}

void print_val_order(struct book library[], int n)
{
    struct book tmp[n];
    struct book temp;

    for (int i = 0; i < n; i++)
        tmp[i] = library[i];

    for (int i = 0; i < n-1; i++)
        for (int k = i+1; k < n; k++)
            if (tmp[i].value > tmp[k].value)
            {
                temp = tmp[i];
                tmp[i] = tmp[k];
                tmp[k] = temp;
            }

    for (int i = 0; i < n; i++)
        printf("%s by %s: $%.2f\n", tmp[i].title, tmp[i].author, tmp[i].value);
}

char * s_gets(char * str, int n)
{
    char * retval;
    char * find;

    retval = fgets(str, n, stdin);
    if (retval)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return retval;
}
