#include <stdio.h>
#include <string.h>

#define MAXTITL 41          /* maximum length of title + 1 */
#define MAXAUTL 41          /* maximum length of author's name + 1 */

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void) {
    struct book library;        /* declare library as a book variable*/

    puts("Please enter the book title.");
    fgets(library.title, MAXTITL, stdin);
    strtok(library.title, "\n");

    puts("Now enter the author.");
    fgets(library.author, MAXAUTL, stdin);
    strtok(library.author, "\n");

    puts("Now enter the value.");
    scanf("%f", &library.value);

    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    puts("Done.");

    return 0;
}
