#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* local functions */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * item);

void InitializeQueue(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq) {
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq) {
    return pq->items == 0;
}

int QueueItemCount(const Queue *pq) {
    return pq->items;
}

bool Enqueue(Item item, Queue *pq) {
    Node * pnew;

    if (QueueIsFull(pq)) {
        return false;
    }

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allcate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (QueueIsEmpty(pq)) {
        pq->front = pnew;
    }
    else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;

    return true;
}

bool Dequeue(Item *pitem, Queue *pq) {
    Node * pt;

    if (QueueIsEmpty(pq)) {
        return false;
    }
    CopyToItem(pq->front, pitem);
    pt = pq->front;         /* save location of front */
    pq->front = pq->front->next;    /* advance to next node */
    free(pt);

    pq->items--;
    if (pq->items == 0) {           /* if *pt is the last item */
        pq->rear = NULL;
    }

    return true;
}

void EmptyTheQueue(Queue *pq) {
    Item dummy;

    while (QueueIsEmpty(pq)) {
        Dequeue(&dummy, pq);
    }
}

static void CopyToNode(Item item, Node * pn) {
    pn->item = item;
}

static void CopyToItem(Node * pn, Item *item) {
    *item = pn->item;
}
