#include <iostream>
#include <queue>
#include <stack>
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST {
private:
    TreeNode* root;
    TreeNode* insertRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else if (value <= root->data) {
            root->left = insertRecursive(root->left, value);
        } else {
            root->right = insertRecursive(root->right, value);
        }
        return root;
    }
    void preorderRecursive(TreeNode* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }
    void inorderRecursive(TreeNode* root) {
        if (root != nullptr) {
            inorderRecursive(root->left);
            std::cout << root->data << " ";
            inorderRecursive(root->right);
        }
    }
    void postorderRecursive(TreeNode* root) {
        if (root != nullptr) {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
            std::cout << root->data << " ";
        }
    }
    void levelOrderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            std::cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    int countNonLeafNodes(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 0;
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
    int countLeafNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
    int height(TreeNode* root) {
        if (root == nullptr)
            return -1;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
    void mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
    bool areEqual(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 != nullptr && root2 != nullptr) {
            return (root1->data == root2->data &&
                    areEqual(root1->left, root2->left) &&
                    areEqual(root1->right, root2->right));
        }
        return false;
    }
public:
    BST() : root(nullptr) {}
    void insertRecursive(int value) {
        root = insertRecursive(root, value);
    }
    void insertIterative(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (value <= current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (value <= parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    bool search(int value) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }
    void deleteByCopying(int value) {
    }
    void deleteByMerging(int value) {
    }
    void preorderRecursive() {
        std::cout << "Preorder Traversal (Recursive): ";
        preorderRecursive(root);
        std::cout << std::endl;
    }
    void inorderRecursive() {
        std::cout << "Inorder Traversal (Recursive): ";
        inorderRecursive(root);
        std::cout << std::endl;
    }
    void postorderRecursive() {
        std::cout << "Postorder Traversal (Recursive): ";
        postorderRecursive(root);
        std::cout << std::endl;
    }
    void preorderIterative() {
        std::cout << "Preorder Traversal (Iterative): ";
        if (root == nullptr)
            return;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            std::cout << current->data << " ";
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
        std::cout << std::endl;
    }
    void postorderIterative() {
        std::cout << "Postorder Traversal (Iterative): ";
        if (root == nullptr)
            return;
        std::stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        do {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            while (root == nullptr && !s.empty()) {
                root = s.top();
                if (root->right == nullptr || root->right == prev) {
                    std::cout << root->data << " ";
                    s.pop();
                    prev = root;
                    root = nullptr;
                } else {
                    root = root->right;
                }
            }
        } while (!s.empty());
        std::cout << std::endl;
    }
    void inorderIterative() {
        std::cout << "Inorder Traversal (Iterative): ";
        if (root == nullptr)
            return;
        std::stack<TreeNode*> s;
        TreeNode* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            std::cout << current->data << " ";
            current = current->right;
        }
        std::cout << std::endl;
    }
    void levelOrder() {
        std::cout << "Level-by-Level Traversal: ";
        levelOrderTraversal(root);
        std::cout << std::endl;
    }
    int countNonLeaf() {
        return countNonLeafNodes(root);
    }
    int countLeaf() {
        return countLeafNodes(root);
    }
    int getHeight() {
        return height(root);
    }
    void mirror() {
        mirrorTree(root);
    }
    bool isEqual(BST& otherTree) {
        return areEqual(root, otherTree.root);
    }
};
int main() {
    BST bst;
    bst.insertRecursive(50);
    bst.insertRecursive(30);
    bst.insertRecursive(70);
    bst.insertRecursive(20);
    bst.insertRecursive(40);
    bst.insertRecursive(60);
    bst.insertRecursive(80);
    bst.inorderRecursive();
    bst.preorderRecursive();
    bst.postorderRecursive();
    bst.levelOrder();
    std::cout << "Non-leaf nodes: " << bst.countNonLeaf() << std::endl;
    std::cout << "Leaf nodes: " << bst.countLeaf() << std::endl;
    std::cout << "Height of the tree: " << bst.getHeight() << std::endl;
    bst.mirror();
    BST bst2;
    bst2.insertRecursive(50);
    bst2.insertRecursive(30);
    bst2.insertRecursive(70);
    bst2.insertRecursive(20);
    bst2.insertRecursive(40);
    bst2.insertRecursive(60);
    bst2.insertRecursive(80);
    std::cout << "Are two BSTs equal? " << (bst.isEqual(bst2) ? "Yes" : "No") << std::endl;
    return 0;
}
