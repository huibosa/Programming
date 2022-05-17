#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef char Item;

typedef struct node {
    Item item;
    struct node * prev;
} Node;

typedef Node * Stack;

void InitializeStack(Stack * ps);
bool StackIsFull(const Stack * ps);
bool StackIsEmpty(const Stack * ps);
unsigned int StackItemCount(const Stack * ps);
bool Push(Item * pitem, Stack * ps);
bool pop(Item * pitem, Stack * ps);
void EmptyTheStack(Stack * ps);

#endif
