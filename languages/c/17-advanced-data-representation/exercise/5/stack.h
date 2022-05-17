#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>
#define NLEN 40
#define MAXSTACK 100

typedef struct item {
    char string[NLEN];
} Item;

typedef struct stack {
    Item item[MAXSTACK];
    int top;
} Stack;

void InitializeStack(Stack * ps);
bool FullStack(const Stack * ps);
bool EmptyStack(const Stack * ps);
bool Push(Item * pitem, Stack * ps);
bool pop(Item * pitem, Stack * ps);
void EmptyTheStack(Stack * ps);

#endif
