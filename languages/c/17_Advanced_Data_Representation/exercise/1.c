// Modify Listing 17.2 so that it displays the movie list both in the original
// order and in reverse order. One approach is to modify the linked-list
// definition so that the list can be traversed in both directions. Another
// approach is to use recursion.


#include <stdio.h>
#include <stdlib.h>             /* for malloc prototype         */
#include <string.h>             /* for strcpy prototype         */
#define TSIZE       45          /* size of array to hold title  */

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
};

void freeall(struct film * pt);
void printoriginal(const struct film * pt);
void printreverse(const struct film * pt);
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

    if (head == NULL) {
        puts("No data entered");
    }
    else {
        puts("Here is the movie list:");
        printoriginal(head);
        puts("Here is the movie list in reverse order");
        printreverse(head);
    }
    freeall(head);

    current = head;
    /* 
    while (current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }
    */

    printf("Bye!\n");

    return 0;
}

void printoriginal(const struct film * pt) {
    struct film * temp;

    temp = (struct film *) pt;
    while (temp != NULL) {
        printf("Movie: %s  Rating: %d\n", temp->title, temp->rating);
        temp = temp->next;
    }
}

void printreverse(const struct film * pt) {
    struct film * temp;

    temp = (struct film *) pt;
    if (temp->next != NULL) {
        printreverse(temp->next);
    }
    printf("Movie %s Rating: %d\n", temp->title, temp->rating);
}

void freeall(struct film * pt) {
    struct film * temp;

    while (pt != NULL) {
        temp = pt;
        pt = pt->next;
        free(pt);
    }
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
