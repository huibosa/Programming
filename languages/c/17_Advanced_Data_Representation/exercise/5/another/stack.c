#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void MakeNode(const Item * pitem, Node * pnew);

void InitializeStack(Stack *ps) {
    *ps = NULL;
}

bool StackIsEmpty(const Stack *ps) {
    return *ps == NULL;
}

bool StackIsFull(const Stack *ps) {
    Node * pnode;
    bool full;

    pnode = (Node *) malloc(sizeof(Node));
    if (pnode == NULL) {
        full = true;
    }
    else {
        full = false;
    }

    return full;
}

unsigned int StackItemCount(const Stack *ps) {
    Node * temp;
    unsigned int count = 0;

    temp = *ps;
    while (temp != NULL) {
        temp = temp->prev;
        count++;
    }

    return count;
}

bool Push(Item *pitem, Stack *ps) {
    if (StackIsFull(ps)) {
        return false;
    }
    Node * pnew;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL) {
        return false;
    }
    MakeNode(pitem, pnew);

    if (StackIsEmpty(ps)) {
        *ps = pnew;
    }
    else {
        pnew->prev = *ps;
        *ps = pnew;
    }

    return true;
}

bool Pop(Item *pitem, Stack *ps) {
    Node * temp;

    if (StackIsEmpty(ps)) {
        return false;
    }

    temp = *ps;
    *pitem = (*ps)->item;
    *ps = (*ps)->prev;
    free(temp);

    return true;
}

void EmptyTheStack(Stack *ps) {
    Node * temp;

    while (*ps != NULL) {
        temp = *ps;
        *ps = (*ps)->prev;
        free(temp);
    }
}

static void MakeNode(const Item * pitem, Node * pnew) {
    pnew->prev = NULL;
    pnew->item = *pitem;
}
