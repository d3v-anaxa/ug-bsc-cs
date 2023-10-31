#include <stdio.h>      /* io operations */
#include <stdlib.h>     /* memory allocations/ setting alias */

#ifndef _BST_
#define _BST_

/* Tree Node structure and creation*/
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

/* Basic Functions of BST*/ 
Node* create(int);
void clean(Node*);
void traverse(Node*);

/* DFS TRAVERSAL OPERATIONS */
void preorder(Node*);
void inorder(Node*);
void postorder(Node*);

#include "bst.c"
#endif
