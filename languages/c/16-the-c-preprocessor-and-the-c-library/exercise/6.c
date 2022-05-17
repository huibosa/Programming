// Modify Listing 16.17 so that it uses an array of struct names elements (as
// defined after the listing) instead of an array of double. Use fewer
// elements, and initialize the array explicitly to a suitable selection of
// names.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NLEN 40
#define SIZE 5

struct names {
    char first[NLEN];
    char last[NLEN];
};

void fillarray(struct names *, int n);
void showarray(const struct names *, int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    srand(time(0));
    struct names students[SIZE];
    fillarray(students, SIZE);

    puts("Random list:");
    showarray(students, SIZE);

    qsort(students, SIZE, sizeof(struct names), mycomp);

    puts("\nSorted list:");
    showarray(students, SIZE);

    return 0;
}

void fillarray(struct names * pt, int n)
{
    int index = 0;

    while (index < n)
    {
        char temp[NLEN];
        int i = 0;

        for (i = 0; i < 5; i++) {
            temp[i] = 'a' + (rand() % 26);
        }
        temp[i] = '\0';

        strcpy(pt[index].first, temp);

        for (i = 0; i < 5; i++) {
            temp[i] = 'a' + (rand() % 26);
        }
        temp[i] = '\0';

        strcpy(pt[index++].last, temp);
    }
}

void showarray(const struct names * pt, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", pt[i].first, pt[i].last);
    }
}

int mycomp(const void * p1, const void * p2)
{
    const struct names * a1 = p1;
    const struct names * a2 = p2;

    return strcmp(a1->first, a2->first);
}
