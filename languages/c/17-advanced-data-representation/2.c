#include <stdio.h>
#include <stdlib.h>             /* for malloc prototype */
#include <string.h>             /* for strcpy prototype */
#define TSIZE       45          /* size of array to hold title   */

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
};

char * s_gets(char * st, int n);

int main(void) {
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

/* gather and store information */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL) {
            head = current;
        } else {
            prev->next = current;
        }
        current->next = NULL;       /* make current the last list */

        strcpy(current->title, input);
        puts("Enter your rating <1-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n') {
            continue;
        }
        puts("Enter next movie title (empty line to stop):");
        prev = current;             /* save current address */
    }

/* show list of movies */
    if (head == NULL) {
        printf("No data entered. ");
    }
    else {
        printf("Here is the movie list:\n");
    }
    current = head;
    while (current != NULL) {
        printf("Movie: %s  Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

/* program done, so free allocated memory */
    current = head;
    while (current != NULL) {
        free(current);
        current = current->next;
    }
    printf("Bye!\n");

    return 0;
}

char * s_gets(char * st, int n) {
    char * retval;
    char * find;

    retval = fgets(st, n, stdin);
    if (retval) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return retval;
}
