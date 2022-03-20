#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node * pnode);

/* interface functions      */
/* set the list to empty    */
void InitializeList(List * plist) {
    plist->head = NULL;
    plist->end = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist) {
    return plist->head == NULL ? true : false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist) {
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL) {
        full = true;
    }
    else {
        full = false;
    }
    free(pt);

    return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist) {
    unsigned int count = 1;
    Node * pnode = plist->head;     /* set to start of list */

    while (pnode != plist->end) {
        count++;
        pnode = pnode->next;    /* set to next node     */
    }

    return count;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation)  */
bool AddItem(Item item, List * plist) {
    Node * pnew;

    if (ListIsFull(plist)) {
        return false;
    }
    pnew = malloc(sizeof(Node));
    if (pnew == NULL) {
        return false;
    }

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (ListIsEmpty(plist)) {
        plist->head = pnew;
        plist->end = pnew;
    }
    else {
        plist->end->next = pnew;
        plist->end = pnew;
    }

    return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List * plist, void (* pfun)(Item)) {
    Node * pnode = plist->head;      /* set to start of list */

    while (pnode != plist->end) {
        (*pfun)(pnode->item);   /* apply function to item */
        pnode = pnode->next;
    }
    (pfun)(pnode->item);
}

/* free memory allocated by malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List * plist) {
    Node * temp;

    while (plist->head != plist->end) {
        temp = plist->head;
        plist->head = plist->head->next;
        free(temp);
    }
    free(plist->head);
}

/* local function definition    */
/* copies an item into a node   */
static void CopyToNode(Item item, Node * pnode) {
    pnode->item = item;         /* structure copy */
}
