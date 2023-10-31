/* Function Definition */
Node* create(int val){
    Node* _t = (Node*)malloc(sizeof(Node));
    _t->val = val;
    _t->left = NULL;
    _t->right = NULL;
    return _t;
}

void clean(Node* root){
    if (!root) return;
    clean(root->left);
    clean(root->right);
    free(root);
}

void preorder(Node* root){
    if (!root) return;
    printf(" %d", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    printf(" %d", root->val);
    inorder(root->right);
}

void postorder(Node* root){
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->val);
}

void traverse(Node* root){
    printf("// preorder -> ");
    preorder(root);
    printf("\n");

    printf("// inorder -> ");
    inorder(root);
    printf("\n");

    printf("// postorder -> ");
    postorder(root);
    printf("\n");
}
