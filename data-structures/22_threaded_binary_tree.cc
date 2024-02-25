#include <iostream>
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;
    Node(int val) : data(val), left(nullptr), right(nullptr), isThreaded(false) {}
};
class ThreadedBinaryTree {
private:
    Node* root;
    Node* findSuccessor(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->isThreaded) return node->right;
        node = node->right;
        while (node && !node->left) node = node->left;
        return node;
    }
    Node* findPredecessor(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->isThreaded) return node->left;
        node = node->left;
        while (node && !node->right) node = node->right;
        return node;
    }
public:
    ThreadedBinaryTree() : root(nullptr) {}
    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    newNode->right = current;
                    newNode->isThreaded = true;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    newNode->isThreaded = true;
                    newNode->right = current->right;
                    current->isThreaded = false;
                    return;
                }
                current = current->right;
            }
        }
    }
    void inorderTraversal() {
        Node* current = root;
        while (current) {
            while (current->left) current = current->left;
            std::cout << current->data << " ";
            current = findSuccessor(current);
        }
        std::cout << std::endl;
    }
    Node* findSuccessor(int value) {
        Node* current = root;
        while (current) {
            if (current->data == value) return findSuccessor(current);
            if (value < current->data) current = current->left;
            else current = current->right;
        }
        return nullptr;
    }
    Node* findPredecessor(int value) {
        Node* current = root;
        while (current) {
            if (current->data == value) return findPredecessor(current);
            if (value < current->data) current = current->left;
            else current = current->right;
        }
        return nullptr;
    }
};
int main() {
    ThreadedBinaryTree tree;
    
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    
    int element = 10;
    Node* successor = tree.findSuccessor(element);
    Node* predecessor = tree.findPredecessor(element);
    if (successor) std::cout << "Successor of " << element << " is " << successor->data << std::endl;
    if (predecessor) std::cout << "Predecessor of " << element << " is " << predecessor->data << std::endl;
    
    return 0;
}
