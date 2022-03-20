#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

/* local data type */
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

/* prototyes for local functions */
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void (*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode ** ptr);
static void DeleteAllNodes(Trnode * root);

/* function definitions */
void InitializeTree(Tree * ptree) {
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree) {
    return ptree->root == NULL ? true : false;
}

bool TreeIsFull(const Tree * ptree) {
    return ptree->size == MAXITEMS ? true : false;
}

int TreeItemCount(const Tree * ptree) {
    return ptree->size;
}

bool InTree(const Item *pi, const Tree *ptree) {
    return SeekItem(pi, ptree).child != NULL ? true : false;
}

bool AddItem(const Item *pi, Tree *ptree) {
    Trnode * new_node;

    if (TreeIsFull(ptree)) {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (SeekItem(pi, ptree).child != NULL) {
        fprintf(stderr, "Attempted to duplicate item\n");
        return false;
    }

    new_node = MakeNode(pi);                /* points to new node */
    if (new_node == NULL) {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    /* succeeded in creating a new node */
    if (ptree->root == NULL) {              /* case 1: tree is empty */
        ptree->root = new_node;             /* new node is tree root */
    }
    else {                                  /* case 2: not empty */
        AddNode(new_node, ptree->root);     /* add node to tree */
    }
    ptree->size++;
    
    return true;
}

bool DeleteItem(Item * pi, Tree * ptree) {
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL) {
        return false;
    }

    if (look.parent == NULL) {              /* delete root item */
        DeleteNode(&(ptree->root));
    }
    else if (look.parent->left == look.child) {
        DeleteNode(&(look.parent->left));
    }
    else {
        DeleteNode(&(look.parent->right));
    }
    ptree->size--;

    return true;
}

void DeleteAll(Tree * ptree) {
    if (ptree != NULL) {
        DeleteAllNodes(ptree->root);
    }
    ptree->root = NULL;
    ptree->size = 0;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item)) {
    if (ptree != NULL) {
        InOrder(ptree->root, pfun);
    }
}

/* local function */
static Trnode * MakeNode(const Item * pi) {
    Trnode * new_node;

    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree) {
    Pair look;

    look.parent = NULL;
    look.child = ptree->root;

    while (look.child != NULL) {
        if (ToLeft(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else {
            break;
        }
    }

    return look;
}

/*
Pair SeekItem(const Item * pi, const Tree * ptree) {
    Pair look;

    look.parent = NULL;
    look.child = ptree->root;

    if (ToLeft(pi, &look.child->item)) {
        if (look.child->left != NULL) {
            return SeekItem(pi, look.child->left);
        }
        else {
            return look;
        }
    }
    else if (ToLeft(pi, &look.child->item)) {
        if (look.child->right != NULL) {
            return SeekItem(pi, look.child->right);
        }
        else {
            return look;
        }
    }
    else {
        return look;
    }
}
*/


static void AddNode(Trnode * new_node, Trnode * root) {
    if (ToLeft(&(new_node->item), &(root->item))) {
        if (root->left != NULL) {
            AddNode(new_node, root->left);      /* empty subtree */
        }
        else {
            root->left = new_node;
        }
    }
    else if (ToRight(&(new_node->item), &(root->item))) {
        if (root->right != NULL) {
            AddNode(new_node, root->right);
        }
        else {
            root->right = new_node;
        }
    }
    else {
        fprintf(stderr, "location error in AddNode()\n");
    }
}

/*
static void AddNode(Trnode * new_node, Trnode * root) {
    Trnode * scan;

    scan = root;
    while (scan->left != NULL || scan->right != NULL) {
        if (ToLeft(&new_node->item, &scan->item)) {
            scan = scan->left;
        }
        else if (ToRight(&new_node->item, &scan->item)) {
            scan = scan->right;
        }
        else {
            fprintf(stderr, "location error in AddNode()\n");
            exit(1);
        }
    }
    if (scan->left == NULL) {
        scan->left = new_node;
    }
    else {
        scan->right = new_node;
    }
}
*/

static bool ToLeft(const Item * i1, const Item * i2) {
    if (strcmp(i1->word, i2->word) < 0) {
        return true;
    }
    else {
        return false;
    }
}

static bool ToRight(const Item * i1, const Item * i2) {
    if (strcmp(i1->word, i2->word) > 0) {
        return true;
    }
    else {
        return false;
    }
}

static void DeleteNode(Trnode ** ptr) {
    Trnode * temp;

    if ((*ptr)->left == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else {
        temp = (*ptr)->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

/* 
void DeleteAllNodes(Trnode * ptr) {
    if (ptr->left != NULL) {
        DeleteAllNodes(ptr->left);
    }
    if (ptr->right != NULL) {
        DeleteAllNodes(ptr->right);
    }
    if (ptr->right == NULL && ptr->left == NULL) {
        free(ptr);
    }
}
*/

static void DeleteAllNodes(Trnode * root) {
    Trnode * temp;

    if (root != NULL) {
        temp = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(temp);
    }
}

static void InOrder(const Trnode * root, void (*pfun)(Item item)) {
    if (root != NULL) {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}
