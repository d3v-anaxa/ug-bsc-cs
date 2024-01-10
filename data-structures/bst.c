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

int height(bst_node *root){
    int res = 0;
    if (root) {
        int left_h = 1 + height(root->left);
        int right_h = 1 + height(root->right);
        res = left_h > right_h ? left_h : right_h;
    }   return res;
}

int leaf_nodes(bst_node *root){
    int count;
    if (!root) {
        count = 0;
    }   else if (root->left == 0x0 && root->right == 0x0) {
        count = 1;
    }   else {
        count = leaf_nodes(root->left) + leaf_nodes(root->right);
    }   return count;
}

int non_leaf_nodes(bst_node *root){
    int count;
    if (!root || (root->left == 0x0 && root->right == 0x0)){
        count = 0;
    }   else {
        count = 1 + non_leaf_nodes(root->left) + non_leaf_nodes(root->right);
    }   return count;
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
        printf("BST height : %4d\n", height(root));
    }
    traversal(root, PREORDER);
    traversal(root, INORDER);
    printf("BST height : %4d\n", height(root));
    clean(root);
}

void test_2(){
    srand(time(0));
    bst_node *root = 0x0;
    for(int i = 0; i < NODE_COUNT; i++){
        insert(&root, rand() % NODE_COUNT - (NODE_COUNT / 2));
        printf("BST height : %4d\n", height(root));
        printf("LEAF NODES : %4d\n", leaf_nodes(root));
        printf("NON-LEAF NODES : %4d\n", non_leaf_nodes(root));
    }
    traversal(root, POSTORDER);
    clean(root);
}

int main(void){
    test_2();
    return 0;
}
