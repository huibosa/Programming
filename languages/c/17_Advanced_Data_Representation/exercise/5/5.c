#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack str_stack;
    Item str;

    InitializeStack(&str_stack);

    printf("Please enter a string: ");
    while (scanf("%40s", str.string) != EOF && !FullStack(&str_stack)) {
        Push(&str, &str_stack);
        printf("Please enter next string: ");
    }
    putchar('\n');
    printf("%d strings has been entered\n", str_stack.top);

    puts("Strings has been entered:");
    while (pop(&str, &str_stack)) {
        printf("%s\n", str.string);
    }

    EmptyTheStack(&str_stack);

    return 0;
}
