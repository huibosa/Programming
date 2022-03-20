#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

void print_item(Item item);

int main(int argc, char * argv[]) {
    FILE * fp;
    char word[MAX_LEN_WORD];
    Tree tree;
    InitializeTree(&tree);
    Item item;
    Item * pitem;
    item.occurence = 1;
    char ch = '\0';

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [FILE]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s for read: %s\n",
                argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", item.word) == 1) {
        if ((pitem = Finditem(&item, &tree)) != NULL) {
            pitem->occurence++;
        }
        else {
            AddItem(&item, &tree);
        }
    }
    fclose(fp);

    while (ch != '3') {
        printf("Menu choices:\n"
               "1) list all words with number of occurence\n"
               "2) find occurence of a specific word\n"
               "3) quit\n");
        scanf("%c", &ch);
        switch (ch) {
            case '1':
                    Traverse(&tree, print_item);
            case '2':
                    printf("Enter word to search: ");
                    scanf("%s", item.word);
                    if ((pitem = Finditem(&item, &tree)) != NULL) {
                        print_item(*pitem);
                    }
                    else {
                        printf("%s not found in text\n", item.word);
                    }
            case '3':
                    DeleteAll(&tree);
                    break;
            default :
                    printf("Choice not available, try again.\n");
        }
        while (getchar() != '\n') {
            continue;
        }
    }
    puts("Bye!");

    return 0;
}

void print_item(Item item) {
    printf("%s - %d\n", item.word, item.occurence);
}
