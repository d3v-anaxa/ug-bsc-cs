#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define NODE_COUNT 200

typedef enum {
    PREORDER,
    POSTORDER,
    INORDER
}   traversal_t;

typedef int T;
typedef struct bst_node {
    T val;
    struct bst_node *left, *right;
}   bst_node;

void insert(bst_node **root, T val){
    if (*root == 0x0){
        bst_node *tmp = (bst_node*) malloc(sizeof(bst_node));
        if (tmp != 0x0){
            tmp->val = val;
            tmp->left = 0x0;
            tmp->right = 0x0;
        }   *root = tmp;
        printf("%12s %4d\n","INSERTED ->", tmp->val);
    } else if (val < (*root)->val) {
        insert(&((*root)->left), val);
    } else if (val >= (*root)->val) {
        insert(&((*root)->right), val);
    }
}

void rm(bst_node **root){
    bst_node *tmp = *root;
    if (!tmp){
        printf("Empty tree\n");
    }   else if (tmp->right){
        rm(&(tmp->right));
    }   else if (tmp->left){
        rm(&(tmp->left));
    }   else {
        printf("%12s %4d\n","DELETED ->", tmp->val);
        *root = 0x0;
        free(tmp);
    }
}

void clean(bst_node *root){
    if (root == 0x0) return;
    clean(root->left);
    clean(root->right);
    free(root);
}

void preorder_priv(bst_node *root){
    if (!root) return;
    printf(" %4d", root->val);
    preorder_priv(root->left);
    preorder_priv(root->right);
}

void inorder_priv(bst_node *root){
    if (!root) return;
    inorder_priv(root->left);
    printf(" %4d", root->val);
    inorder_priv(root->right);
}

void postorder_priv(bst_node *root){
    if (!root) return;
    postorder_priv(root->left);
    postorder_priv(root->right);
    printf(" %4d", root->val);
}

void traversal(bst_node *root, traversal_t x){
    if (!root) {
        printf("Empty tree!\n");
    }   else {
        switch (x){
            case PREORDER:
                printf("%-12s ", "PREORDER :");
                preorder_priv(root);
                break;
            case INORDER:
                printf("%-12s ", "INORDER :");
                inorder_priv(root);
                break;
            case POSTORDER:
                printf("%-12s ", "POSTORDER :");
                postorder_priv(root);
                break;
            default:
                printf("SELECT TRAVERSAL ALGORITHM");
        }   printf("\n");
    }
}

int capacity(bst_node *root){
    int res = 0;
    if (root != 0x0)
        res = 1 + capacity(root->left) + capacity(root->right);
    return res;
}

void test(){
    srand(time(0));
    bst_node *root = 0x0;
    for(int i = 0; i < NODE_COUNT; i++){
        rand() % 2 ? insert(&root, rand() % NODE_COUNT - (NODE_COUNT / 2)) : rm(&root);
    }
    traversal(root, PREORDER);
    traversal(root, INORDER);
    clean(root);
}

int main(void){
    test();
    return 0;
}
