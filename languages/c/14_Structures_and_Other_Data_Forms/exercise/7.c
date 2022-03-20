// Modify Listing 14.14 so that as each record is read from the file and shown
// to you, you are given the chance to delete the record or to modify its
// contents. If you delete the record, use the vacated array position for the
// next record to be read. To allow changing the existing contents, you’ll need
// to use the "r+b" mode instead of the "a+b" mode, and you’ll have to pay more
// attention to positioning the file pointer so that appended records don’t
// overwrite existing records. It’s simplest to make all changes in the data
// stored in program memory and then write the final set of information to the
// file. One approach to keeping track is to add a member to the book structure
// that indicates whether it is to be deleted. 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char *st, int n);
struct book update_entry(struct book);
void eatline(void);

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks))
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
                        library[count].author, library[count].value);
        printf("Press d to delete this book, c to change "
               "it or ent to keep it: \n");
        switch (getchar())
        {
            case 'd': eatline();
                      break;
            case 'c': eatline();
                      library[count] = update_entry(library[count]);
            case '\n':
            default:
                      count++;
        }
        if (count == MAXBKS)
        {
            fputs("The book.dat file is full.", stderr);
            exit(1);
        }
        fclose(pbooks);
        if ((pbooks = fopen("book.dat", "w+b")) == NULL)
        {
            fputs("Can't open book.dat file\n", stderr);
            exit(1);
        }
        puts("Please add new book titles.");
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
                puts("ENter the next title.");
        }
        if (count > 0)
        {
            puts("Here is the list of your books:");
            for (int i = 0; i < count; i++)
                printf("%s by %s: $%.2f\n", library[i].title,
                                 library[i].author, library[i].value);
            fwrite(&library[0], size, count, pbooks);
        }
        else
            puts("No books ? Too bad.\n");
        puts("Bye.\n");
        fclose(pbooks);
        return 0;
    }
}

char * s_gets(char * st, int n)
{
    char * retval;
    char * find;

    retval = fgets(st, n, stdin);
    if (retval)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return retval;
}

struct book update_entry(struct book entry)
{
    char title[MAXTITL];
    char author[MAXAUTL];
    char value[10];

    printf("Title: %s\n"
           "Enter new title or enter to keep unchanged: ",
           entry.title);
    s_gets(title, MAXTITL);
    if (title[0] != '\0')
        strcpy(entry.title, title);
    printf("Author: %s\n"
           "Enter new author or enter to keep unchanged: ",
           entry.author);
    s_gets(author, MAXAUTL);
    if (author[0] != '\0')
        strcpy(entry.author, author);
    printf("Value: %.2f\n"
           "Enter new value or enter to keep unchanged: ",
           entry.value);
    if (value[0] != '\0')
        entry.value = atoi(value);

    return entry;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
