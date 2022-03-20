## Exploring Data Representation

* Also, some compilers set a default limit for the amount of memory available
  for automatic storage class variables.
* You can fix that by making the array a static or external array or by
  instructing the compiler to use a larger stack, but that’s not fixing the
  real problem.

```c
#define TSIZE   45
struct film {
    char title[TSIZE];
    int rating;
};

/* some code */

    int n, i;
    struct film * movies;       /* pointer to a structure */

    /* some code */
    
    printf("Enter the maximun number of movies you'll enter:\n");
    scanf("%d", &n);
    movies = (struct film *) malloc(n * sizeof(struct film));
```

## Beyond the Array to the Linked List

Comparing calling `malloc()` once, asking for enough space for 300 film
structures, and calling `malloc()` 300 times, each time asking for enough space
for one film structure.

* The first case allocates the memory as one contiguous memory block and all
  you need to keep track of the contents is a single pointer-to-struct variable
  (film) that points to the first structure in the block.  Simple array
  notation lets the pointer access each structure in the block.
* The second approach is that there is no guarantee that consecutive calls to
  `malloc()` yield adjacent blocks of memory. This means the structures won’t
  necessarily be stored contiguously. Therefore, instead of storing one pointer
  to a block of 300 structures, you need to store 300 pointers, one for each
  independently allocated structure!

![1](./images/allocatestruct.png)

One solution is to create large array of pointers and assign values to the
pointers

```c
#define TSIZE       45        /* size of array to hold title   */
#define FMAX        500       /* maximum number of film titles */

struct film {
    char title[TSIZE];
    int rating;
};
/* some code */
    struct film * movies[FMAX];     /* array of pointers to structures */
    int i;
    /* some code */
    movies[i] = (struct film *) malloc(sizeof(struct film));
```

* This approach saves a lot of memory.
* It still wastes the space occupied by unused pointers, however, and it still
  imposes a 500-structure limit.

---

* There’s a better way. Each time you use `malloc()` to allocate space for a
  new structure, you can also allocate space for a new pointer.
* The trick to avoiding this potential problem is to redefine the structure so
  that each structure includes a pointer to the next structure.
* Then, each time you create a new structure, you can store its address in the
  preceding structure. In short, you need to redefine the film structure.

```c
#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
}
```

A structure can’t contain in itself a structure of the same type, but it can
contain a pointer to a structure of the same type.

Such a definition is the basis for defining a *linked list*—a list in which
each item contains information describing where to find the next item.

Suppose a user enters `Modern Times` as a `title` and `10` as a `rating`.

* The program would allocate space for a `film` structure, copy the string
  `Modern Times` into the `title` member, and set the `rating` member to `10`.
* To indicate that no structure follows this one, the program would set the
  `next` member pointer to `NULL`.
* you need to keep track of where the first structure is stored. You can do
  this by assigning its address to a separate pointer that we’ll refer to as
  the *head pointer*. The head pointer points to the first item in a linked
  list of items.

![2](./images/linklist.png)

Now suppose the user enters a second movie and rating—for example, `Midnight in
Paris` and `8`.

* The program allocates space for a second `film` structure, storing the
  address of the new structure in the `next` member of the first structure
  (overwriting the `NULL` previously stored there) so that the `next` pointer
  of one structure points to the following structure in the linked list.
* Then the program copies `Midnight in Paris` and `8` to the new structure and
  sets its `next` member to `NULL`, indicating that it is now the last
  structure in the list.

![3](./images/linklist2.png)

![4](./images/linklist3.png)

### Using a Link List

```c
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
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <1-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n') {
            continue;
        }
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

/* show list of movies */
    if (head == NULL) {
        printf("No data entered. ");
    } else {
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
```

#### Displaying a List

```c
current = head;
while (current->next != NULL)
{
    /* do something*/
    current = current->next;
}
```

* Using `head` instead of creating a new pointer (`current`) to march through
  the listwould change the value of `head`, and the program would no longer
  have a way to find the beginning of the list.

#### Creating The List

* The address of the very first structure should be stored in the pointer
  variable `head`.
* The address of each subsequent structure should be stored in the `next` member
  of the structure that precedes it.
* Therefore, the program needs a way to know whether it’s dealing with the
  first structure or not.
* A simple way is to initialize the `head` pointer to NULL when the program
  starts.

```c
if (head == NULL)               /* first structure */
    head = current;
else
    prev->next = current;       /* subsequent structure */
```

* You should set the `next` member to `NULL` to indicate that the current
  structure is the last one in the list.
* Finally, you should prepare the program for the next cycle of the input loop.
  In particular, you need to set `prev` to point to the current structure,

```c
prev = current;
```

#### Freeint List Memory

```c
current = head;
while (current->next != NULL)
{
    free(current);
    current = current->next;
}
```

### Afterthoughts

* It fails to check whether `malloc()` finds the requested memory,
* It doesn’t have any provisions for deleting items from the list.
* You can add code that checks whether malloc()’s return value is NULL (the
  sign it failed to obtain the memory you wanted).
* If the program needs to delete entries, you can write some more code to do
  that.

> This ad hoc approach to solving problems and adding features as the need
> arises isn’t always the best programming method.

In particular, it tends to intermingle coding details and the conceptual model.

* For example, in the sample program, the conceptual model is that you add
  items to a list.
* The program obscures that interface by pushing details such as `malloc()` and
  the `current->next` pointer into the foreground.

## Abstract Data Types (ADTs)

What constitutes a *type*? A type specifies two kinds of information: a set of
properties and a set of operations.

* The `int` type’s property is that it represents an integer value and, shares
  the properties of integers.
* The allowed arithmetic operations are changing the sign, adding two `int`s,
  subtracting two `int`s, dividing one `int` by another, and taking the modulus
  of one `int` with respect to another.
* When yo declare a variable to be an `int`, you're saying that these and only
  these operations can affect it.

Computer science has developed a very successful way to define new data types.
It’s a threestep process that moves from the abstract to the concrete:

1. Provide an abstract description of the type’s properties and of the
   operations you can perform on the type. This description shouldn’t be tied
   to any particular implementation. It shouldn’t even be tied to a particular
   progarmming language. Such a formal abstract description is called an
   *abstract data type* (ADT).
2. Develop a programming interface that implements the ADT. That is, indicate
   how to store the data and describe a set of functions that perform the
   desired operations. In C, for example, you might supply a structure
   definition along with prototypes for functions to manipulate the structures.
   These functions play the same role for the user-defined type that C’s
   built-in operators play for the fundamental C types. Someone who wants to
   use the new type will use this interface for her or his programming.
3. Write code to implement the interface. This step is essential, of course,
   but the programmer using the new type need not be aware of the details of
   the implementation.

### Getting Abstract

Some useful operations:

* Initializing a list to empty
* Adding an item to the end of a list
* Determining whether the list is empty
* Determining whether the list is full
* Determining how many items are in the list
* Visiting each item in a list to perform some action, such as displaying the
  item

A more general list of operations for lists might include the following:

* Inserting an item anywhere in the list
* Removing an item from the list
* Retrieving an item from the list (list left unaltered)
* Replacing one item in the list with another
* Searching for an item in the list

```c
Type Name:              Simple List
Type Properties:        Can hold a sequence of items.
Type Operations:        Initialize list to empty.
                        Determine whether list is empty.
                        Determine whether list is full.
                        Determine number of items in the list.
                        Add item to end of list.
                        Traverse list, processing each item in list.
                        Empty the list.
```

### Building an Interface

The first part describe how the data will be represented.

The interface design should parallel the ADT description as closely as
possible. Therefore, it should be expressed in terms of some general `Item`
type instead of in terms of some specific type, such as `int` or `struct film`.
One way to do this is to use C’s `typedef`.

```c
#define TSIZE 45    /* size of array to hold title */
struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item;
```

---

Having defined Item, you now have to decide how to store items of that type.

```c
typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef Node * List;
```

* In a linked list implementation, each link is called a *node*.
* Each node contains information that forms the contents of the list along with
  a pointer to the next node.

---

Finally, to manage a linked list, we need a pointer to its beginning, and we've
used `typedef` to make `List` the name for a pointer of this type.

```c
List movies;
```

* Established `movies` a pointer suitable for referring to a linked list.

---

Another way to define the `List` type is to incorporate a variable to keep
track of the number of entries.

```c
typedef struct list {
    Node * head;        /* pointer to the head of list      */
    int size;           /* number of entries in list        */
} List;                 /* alternative definition of list   */
```

* You could add a second pointer to keep track of the end of the list.

---

A program should initialize the head pointer to `NULL` when starting out:

```c
movies = NULL;          // you should not use code like this
```

The structure implementation of a `List` type would require the following
information:

```c
movies.next = NULL;
movies.size = 0;
```

---

```c
initializeList(movies);
```

Programmers need to know only that they should use the `InitializeList()`
function to initialize a list. They don’t have to know the exact data
implementation of a List variable.

This is an example of *data hiding*, the art of concealing details of data
representation from the higher levels of programming.

To guide the user, you can supply a function prototype along these lines:

```c
/* operation:           initialize a list                       */
/* preconditions:       plist points to a list                  */
/* postconditions:      the list is initialized to empty        */
void InitializeList(List * plist);
```

There are three points you should notice.

* First, the comments outline preconditions—that is, conditions that should
  hold before the function is called. Here, for example, you need a list to
  initialize.
* Second, the comments outline postconditions—that is, conditions that should
  hold after the function executes.
* Finally, the function uses a pointer to a list instead of a list as its
  argument, so this would be the function call:

```c
InitializeList(&movies);
```

* The reason is that C passes arguments by value, so the only way a C function
  can alter a variable in the calling program is by using a pointer to that
  variable.

> Here the restrictions of the language make the interface deviate slightly
> from the abstract description.

---

The C way to tie all the type and function information into a single package is
to place the type definitions and function prototypes (including precondition
and postcondition comments) in a header file.  

This file should supply all the information a programmer needs to use the type.

> If your compiler doesn’t support the C99 `bool` type, you can use:

```c
enum bool {false, true};    /*define bool as type, false, true as values*/
```

---

```c
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* program-specific declarations */

#define TSIZE 45    /* size of array to hold title */
struct film {
    char title[TSIZE];
    int rating;
};

/* general type definitions */

typedef struct film Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef Node * List;

/* function prototypes */

void initializeList(List * plist);
bool ListIsFull(const List * plist);
bool AddItem(Item item, List * plist);
void Traverse(const List * plist, void (* pfun)(Item item));
void EmptyTheList(List * plist);

#endif
```

* Only the `InitializeList()`, `AddItem()`, and `EmptyTheList()` functions
  modify the list, so, technically, they are the only methods requiring a
  pointer argument.
* However, it can get confusing if the user has to remember to pass a `List`
  argument to some functions and an address of a `List` as the argument to
  others. So, to simplify the user’s responsibilities, all the functions use
  pointer arguments.

### Using the Interface

```
Create a List variable.
Create a Item variable.
Initialize the list to empty.
While the list isn't full and while there's more input:
    Read the input into the Item variablel.
    Add the item to the end of the list.
Visit each item in the list any display it.
```

### Implementing the Interface

The complete program, then, consists of three files:

* `list.h`, which defines the data structures and provides prototypes for the
  user interface,
* `list.c`, which provides the function code to implement the interface,
* `films.c`, which is a source code file that applies the list interface to a
  particular programming problem.

![1](./images/list1.png)

![2](./images/list2.png)

![3](./images/list3.png)

### Program Notes

The `InitializeList()` function initializes a list to empty. In our
implementation, that means setting a type `List` variable to `NULL`.

```c
void ListIsEmpty(const List * plist)
{
    *plist = NULL;
}
```

---

The `ListIsEmpty()` function depends on the `list` variable being set to `NULL`
when the list is empty. Therefore, it’s important to initialize a list before
first using the `ListIsEmpty()` function.

```c
bool ListIsEmpty(const List * plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}
```

Also, if you were to extend the interface to include deleting items, you should
make sure the deletion function resets the list to empty when the last item is
deleted.

With a linked list, the size of the list is limited by the amount of memory
available.

---

The `ListIsFull()` function tries to allocate enough space for a new item.

```c
bool ListIsFull(const List * plist) {
    Node * pt;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL) {
        free(pt);
        return true;
    }
    else {
        free(pt);
        return false;
    }
}
```

* If it fails, the list is full.
* If it succeeds, it has to free the memory it just allocated so that it is
  available for a real item.

---

The `ListItemCount()` function uses the usual linked-list algorithm to traverse
the list, counting items as it goes:

```c
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;          /* set start of list */

    while (pnode != NULL) {
        count++;
        pnode = pnode->next;        /* set to next node  */
    }

    return count;
}
```

---

```c
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;           /* quit function on failure */

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {         /* empty list, so place */
        *plist = pnew;          /* pnew at head of list */
    }
    else {
        while (scan->next != NULL) {
            scan = scan->next;  /* find end of list     */
        }
        scan->next = pnew;      /* add pnew to end       */
    }

    return true;
}
```

* The first thing the `AddItem()` function does is allocate space for a new
  node.  If this succeeds, the function uses `CopyToNode()` to copy the item to
  the node.
* Then it sets the next member of the node to `NULL`. This, as you’ll recall,
  indicates that the node is the last node in the linked list.
* Finally, after creating the node and assigning the correct values to its
  members, the function attaches the node to the end of the list. If the item
  is the first item added to the list, the program sets the `head` pointer to
  the first item. (Remember, `AddItem()` is called with the address of the head
  pointer as its second argument, so `*plist` is the value of the head
  pointer.) Otherwise, the code marches through the linked list until it finds
  the item having its next member set to `NULL`. That node is currently the
  last node, so the function resets its next member to point to the new node.

> Also, it’s possible a user might do something else to allocate memory between
> calling `ListIsFull()` and calling `AddItem()`, so it’s best to check whether
> `malloc()` worked.

---

```c
void Traverse(const List * plist, void (* pfun)(Item item))
{
    Node * pnode = *plist;

    while (pnode != NULL) {
        (*pfun)(*pnode->item)
        pnode = pnode->next;
    }

}
```

---

```c
void EmptyTheList(List * plist)
{
    Node * temp;

    while (*plist != NULL) {
        temp = (*plist)->next;      /* save address of next node */
        free(*plist);               /* free current node         */
        *plist = temp;              /* advance to next node      */
    }
}
```

* The implementation indicates an empty list by having the List variable being
  set to NULL . 
* Therefore, this function needs to be passed the address of the `List`
  variable to be able to reset it.
* Because `List` already is a pointer, `plist` is a pointer to a pointer. Thus,
  within the code, the expression `*plist` is type `pointer-to-Node`.
* When the list terminates, `*plist` is `NULL`, meaning the original actual
  argument is now set to `NULL`. 

#### Note The Limitation of `const`

```c
*plist = (*plist)->next;        // not allowed if *plist is const
```

* `const List * plist` indicates the intent that these functions don’t alter
  the list.
* Here, `const` does provide some protection. It prevents `*plist` (the
  quantity to which `plist` points) from being changed.
* In this program, `plist` points to `movies`, so `const` prevents those
  functions from changing `movies`, which, in turn, points to the first link in
  the list.

---

```c
(*plist)->item.rating = 3;      // allowed evenif *plist is const
```

* The fact that `*plist` and `movies` are treated as `const` doesn’t mean that
  data pointed to by `*plist` or `movies` is `const`.

### Contemplating Your Work

The ADT version expresses the program in terms of the problem to be solved, not
in terms of the low-level tools needed to solve the problem. It is oriented to
the end user’s concerns and is much easier to read.

---

Suppose you need to store an inventory of your relatives: names, relationships,
addresses, and phone numbers. First, you would go to the `list.h` file and
redefine the Item type:

```c
typedef strct itemtag {
    char fname[14];
    char lname[14];
    char relationship[14];
    char address[14];
    char phonenum[14];
} Item;
```

* You would have to redefine the `CopyToNode()` function. For example, if an
  item were an array, you could'nt copy it by assignment.

The current `AddItem()` function is a bit inefficient because it always starts
at the beginning of the list and then searches for the end. You can fix this
problem by keeping track of the end of the list. For example, you can redefine
the List type this way:

```c
typedef strct list {
    Node * head;        /* points to the head of list */
    Node * end;         /* points to the end of list  */
} List;
```

## Getting Queued with an ADT

The abstract data type approach to programming in C involves the following
three steps:

1. Describing a type, including its operations, in an abstract, general
   fashion.
2. Devising a function interface to represent the new type.
3. Writing detailed code to implement the interface.

### Defining the Queue Abstract Data Type

A *queue* is a list with two special properties.

* First, **new items can be added only to the end of the list.** In this
  respect, the queue is like the simple list.
* Second, **items can be removed from the list only at the beginning**. You can
  visualize a queue as a line of people buying tickets to a theater. You join
  the line at the end, and you leave the line at the front, after purchasing
  your tickets.

A queue is a *first in, first out* (FIFO) data form, just the way a movie line
is (if no one cuts into the line).

```c
Type Name:          Queue
Type Properties:    Can hold an ordered sequence of items.
Type Operations:    Initialize queue to empty.
                    Determine whether queue is empty.
                    Determine whether queue is full.
                    Determine number of items in the queue.
                    Add item to rear of queue.
                    Remove and recover item from front of queue.
```

### Defining an Interface

```c
void InitializeQueue(Queue * pq);
bool QueueIsFull(const Queue * pq);
bool QueueIsEmpty(const Queue * pq);
bool EnQueue(Item item, Queue * pq);
bool DeQueue(Item * pitem, Queue * pq);
void EmptyTheQueue(Queue * pq);
```

### Implementing the Interface Data Representation

The first step is deciding what C data form to use for a queue. One possibility
is an array.

* The advantages to arrays are that they’re easy to use and that adding an item
  to the end of an array’s filled portion is easy.
* The problem comes with removing an item from the front of the queue. In the
  analogy of people in a ticket line, removing an item from the front of the
  queue consists of copying the value of the first element of the array
  (simple) and then moving each item left in the array one element toward the
  front.

![4](./images/queue.png)

A second way to handle the removal problem in an array implementation is to
leave the remaining elements where they are and, instead, change which element
you call the front.

* This method’s problem is that the vacated elements become dead space, so the
  available space in the queue keeps decreasing.

![5](./images/queue2.png)

A clever solution to the dead space problem is to make the queue *circular*.

This means wrapping around from the end of the array to the beginning. That is,
consider the first element of the array as immediately following the last
element so that when you reach the end of the array, you can start adding items
to the beginning elements if they have been vacated.

---

Yet another solution is to use a linked list. This has the advantage that
removing the front item doesn’t require moving all the other items. Instead,
you just reset the `front` pointer to point to the new first element.

```c
typedef int Item;

typedef struct Node {
    Item item;
    struct node * next;
} Node;
```

![5](./images/qlinklist.png)

For the queue, you need to keep track of the front and rear items. You can use
pointers to do this. Also, you can use a counter to keep track of the number of
items in a queue. Thus, the structure will have two pointer members and one
type `int` member:

```c
typedef struct queue {
    Node * front;       /* pointer to front of queue */
    Node * rear;        /* pointer to rear of queue  */
    int items;          /* number of items in queue  */
} Queue;
```

Next, think about the size of a queue. With a linked list, the amount of
available memory sets the limit, but often a much smaller size is more
appropriate.

### Implementing the Interface Functions

First, initializing a queue to "empty" means setting the `front` and `rear`
pointers to `NULL` and setting the item count (the items member) to `0`.

```c
void InitializeQueue(Queue * pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}
```

---

Next, the items member makes it easy to check for a full queue or empty queue
and to return the number of items in a queue:

```c
bool QueueIsFull(const Queue * pq) {
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pq) {
    return pq->items == 0;
}

int QueueItemCount(const Queue * pq) {
    return pq->items;
}
```

---

Adding an item to the queue involves the following steps: 

1. Creating a new node. 
2. Copying the item to the node. 
3. Setting the node’s next pointer to `NULL`, identifying the node as the last
   in the list. 
4. Setting the current `rear` node’s next pointer to point to the new node,
   linking the new node to the queue. 
5. Setting the `rear` pointer to the new node, making it easy to find the last
   node. 
6. Adding `1` to the item count.

Also, the function has to handle two special cases.

* First, if the queue is empty, the front pointer should be set to point to the
  new node.  That’s because when there is just one node, that node is both the
  front and the rear of the queue.
* Second, if the function is unable to obtain memory for the node, it should do
  something. Because we envision using small queues, such failure should be
  rare, so we’ll simply have the function terminate the program if the program
  runs out of memory.

```c
bool EnQueue(Item item, Queue * pq) {
    Node * pnew;

    if (QueueIsFull(pq))
        return false;
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew = NULL);
        exit(1);

    CopytoNode(item, pnew);
    pnew->next = NULL;

    if (QueueIsEmpty(pq))
        pq->front = pnew;       /* items goes to front  */
    else
        pq->rear->next = pnew;  /* link at end of queue */
    pq->rear = pnew;            /* record location of end */
    pq->items++;                /* one more item in queque*/
}

```

---

The `CopyToNode()` function is a `static` function to handle copying the item
to a node: 

```c
void CopyToNode(Item item, Node * pnode) {
    pnode->item = item;
}
```

---

Removing an item from the front of the queue involves the following steps: 

1. Copying the item to a waiting variable 
2. Freeing the memory used by the vacated node 
3. Resetting the `front` pointer to the next item in the queue 
4. Resetting the `front` and `rear` pointers to `NULL` if the last item is
   removed 
5. Decrementing the item count

```c
bool DeQueue(Item * pitem, Queue * pq) {
    Node * pt;

    if (QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;

    return true;
}
```

There are a couple of pointer facts you should note.

* First, the code doesn’t explicitly set the front pointer to `NULL` when the
  last item is deleted. That’s because it already sets the `front` pointer to
  the next pointer of the node being deleted. If that node is the last node,
  its next pointer is `NULL`, so the front pointer gets set to `NULL`.
* Second, the code uses a temporary pointer `pt` to keep track of the deleted
  node’s location. That’s because the official pointer to the first node
  `pq->front` gets reset to point to the next node, so without the temporary
  pointer, the program would lose track of which block of memory to free.

---

We can use the `DeQueue()` function to empty a queue. Just use a loop calling
`DeQueue()` until the queue is empty:

```c
void EmptyTheQueue(Queue * pq) {
    Item dummy;

    while (*pq != NULL) {
        DeQueue(&dummy, pq);
    }
}
```

> After you’ve defined an ADT interface, **you should use only the functions of
> the interface to handle the data type**. If, in a program using the ADT, you
> decided to manipulate parts of the queue directly, you might mess up the
> coordination between the functions in the interface package.


## Simulating with a Queue

## The Linked List Versus the Array

| Data Form   | Pros                                                                      | Cons                                                              |
|-------------|---------------------------------------------------------------------------|-------------------------------------------------------------------|
| Array       | Directly supported by C. Provides random access. at compile time.         | Size determined Inserting and deleting elements is time consuming |
| Linked list | Size determined during runtime. Inserting and deleting elements is quick. | No random access. User must provide programming support.          |

* To insert an element in an array, you have to move elements to make way for
  the new element, The closer to the front the new element goes, the more
  elements have to be moved.
* To insert a node in a linked list, however, you just have to assign values to
  two pointers, as shown in 
* Removing an element from an array involves a wholesale relocation of
  elements,
* Removing a node from a linked list involves resetting a pointer and freeing
  the memory used by the deleted node. 

![1](./images/arrayinsert.png)

![1](./images/linklistinsert.png)

---

Next, consider how to access the members of a list.  

* With an array, you can use the array index to access any element immediately.
  This is called *random access*.
* With a linked list, you have to start at the top of the list and then move
  from node to node until you get to the node you want, which is termed
  *sequential access*.

> You can have sequential access with an array, too. Just increment the array
> index by one step each to move through the array in order.

---

Binary search:

![1](./images/binary_search.png)

## Binary Search Trees

The binary search tree is a linked structure that incorporates the binary
search strategy.

Each node in the tree contains an item and two pointers to other nodes, called
*child nodes*. The idea is that each node has two child nodes—a left node and
a right node.

The ordering comes from the fact that the item in a left node precedes the item
in the parent node, and the item in the right node follows the item in the
parent node. This relationship holds for every node with children.

Furthermore, all items that can trace their ancestry back to a left node of a
parent contain items that precede the parent item in order, and every item
descended from the right node contains items that follow the parent item in
order.

The top of the tree, is called the root. A tree is a hierarchical organization,
meaning that the data is organized in ranks, or levels, with each rank, in
general, having ranks above and below it. If a binary search tree is fully
populated, each level has twice as many nodes as the level above it.

![1](./images/binary_search_tree.png)

Each node in the binary search tree is itself the root of the nodes descending
from it, making the node and its descendants a *subtree*.  

Suppose you want to find an item—call it the *target*-in such a tree. If the
item precedes the root item, you need to search only the left half of the tree,
and if the target follows the root item, you need to search only the right
subtree of the root node. Therefore, one comparison eliminates half the tree.

Suppose you search the left half. That means comparing the target with the item
in the left child. If the target precedes the left-child item, you need to
search only the left half of its descendants, and so on. As with the binary
search, each comparison cuts the number of potential matches in half.

A binary search tree, then, combines a linked structure with binary search
efficiency. The programming price is that putting a tree together is more
involved than creating a linked list.

### A Binary Tree ADT

Type Operations:

* Initializing tree to emtpy
* Determining whether tree is empty
* Determining whether tree is full
* Determining the number of items in the tree
* Adding an item to the tree
* Removing an item from the tree
* Searching the tree for an item
* Visiting each item in the tree
* Empty the tree

### The Binary Search Tree Interface

```c
typedef struct item {
    char first[40];
    char last[40];
} Item;

typedef struct trnode {
    Item item;
    struct trnode * left;
    struct trnode * right;
} Trnode;

typedef struct tree {
    Trnode * root;
    int size;
} Tree;
```

### The Binary Tree Implementation

### Adding an Item

When adding an item to the tree, you should first check whether the tree has
room for a new node.

Then, because the binary search tree is defined so that it has no duplicate
items,you should check that the item is not already in the tree.

If the new item clears these first two hurdles, you create a new node, copy the
item to the node, and set the node’s left and right pointers to NULL. This
indicates that the node has no children.

Then you should update the size member of the Tree structure to mark the adding
of a new item.

Next, you have to find where the node should be located in the tree. If the
tree is empty, you should set the root pointer to point to the new node.
Otherwise, look through the tree for a place to add the node.  The AddItem()
function follows this recipe, offloading some of the work to functions not yet
defined: `SeekItem()`, `MakeNode()`, and `AddNode()`.

---

Three of the interface functions involve searching the tree for a particular
item: `AddItem()`, `InTree()`, and `DeleteItem()`. This implementation uses a
`SeekItem()` function to provide that service.

The `DeleteItem()` function has an additional requirement: It needs to know the
parent node of the deleted item so that the parent’s child pointer can be
updated when the child is deleted.

Therefore, we designed `SeekItem()` to return a structure containing two point-
ers:

* One pointing to the node containing the item (`NULL` if the item isn’t found)
* One pointing to the parent node (`NULL` if the node is the root and has no
  parent). The structure type is defined as follows:

```c
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;
```

The `SeekItem()` function can be implemented recursively or to use a while
loop. Like `AddNode()`, `SeekItem()` uses `ToLeft()` and `ToRight()` to
navigate through the tree.

* `SeekItem()` initially sets the `look.child` pointer to point to the root of
  the tree, and then it resets `look.child` to successive subtrees as it traces
  the path to where the item should be found.
* Meanwhile, `look.parent` is set to point to successive parent nodes.
* If no matching item is found, `look.child` will be `NULL`.
* If the matching item is in the root node, `look.parent` is `NULL` because the
  root node has no parent.

#### Considerations in Deleting an Item

![1](./images/deleteleaf.png)

Here the node to be deleted has no children (Such a node is called a *leaf*.)
All that has to be done in this case is to reset a pointer in the parent node
to `NULL` and to use the `free()` function to reclaim the memory used by the
deleted node.

---

![2](./images/deleteonechild.png)

![3](./images/deletetwo.png)

#### Deleting an Item

If `look.child` is NULL, the search failed to find the item, and the
`DeleteItem()` function quits, returning `false`.

If the Item is found, the function handles three cases.

* First, a `NULL` value for `look.parent` means the item was found in the root
  node. In this case, there is no parent node to update. Instead, the program
  has to update the `root` pointer in the Tree structure. Therefore, the
  function passes the address of that pointer to the `DeleteNode()` function.
* Otherwise, the program determines whether the node to be deleted is the left
  child or the right child of the parent, and then it passes the address of the
  appropriate pointer.
