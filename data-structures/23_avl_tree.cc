#include <iostream>
#include <algorithm>
class AVLTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;
        Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };
    Node* root;
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    void updateHeight(Node* node) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    Node* balance(Node* node, int value) {
        updateHeight(node);
        int balanceFactor = getBalance(node);
        if (balanceFactor > 1 && value < node->left->data)
            return rotateRight(node);
        if (balanceFactor < -1 && value > node->right->data)
            return rotateLeft(node);
        if (balanceFactor > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
        return balance(node, value);
    }
    void inorderTraversal(Node* node) {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }
public:
    AVLTree() : root(nullptr) {}
    void insert(int value) {
        root = insert(root, value);
    }
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};
int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    std::cout << "In-order Traversal: ";
    tree.inorderTraversal();
    return 0;
}
