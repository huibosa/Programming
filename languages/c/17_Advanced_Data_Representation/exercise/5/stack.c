#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void InitializeStack(Stack *ps) {
    ps->top = 0;
}

bool FullStack(const Stack *ps) {
    return ps->top == MAXSTACK ? true : false;
}

bool EmptyStack(const Stack *ps) {
    return ps->top == 0 ? true : false;
}

bool Push(Item *pitem, Stack *ps) {
    if (FullStack(ps)) {
        fprintf(stderr, "Stack is full\n");
        return false;
    }

    ps->item[ps->top++] = *pitem;

    return true;
}

bool pop(Item *pitem, Stack *ps) {
    if (EmptyStack(ps)) {
        return false;
    }
    else {
        *pitem = ps->item[ps->top-1];
        ps->top--;
        return true;
    }
}

void EmptyTheStack(Stack *ps) {
    ps->top = 0;
}
