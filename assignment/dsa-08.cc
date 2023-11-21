/*
   WAP to create a Binary Search Tree and include following operations in tree:
   - [x] i. Insertion (Recursive and Iterative Implementation)
   - [] ii. Deletion by copying
   - [] iii. Deletion by Merging
   - [x] iv. Search a no. in BST
   - [x] v. Display its preorder, postorder and inorder traversals Recursively
   - [] vi. Display its preorder, postorder and inorder traversals Iteratively
   - [] vii. Display its level-by-level traversals
   - [x] viii. Count the non-leaf nodes and leaf nodes
   - [] ix. Display height of tree
   - [] x. Create a mirror image of tree
   - [x] xi. Check whether two BSTs are equal or not
 */

#include <bits/stdc++.h>
using namespace std;
class BinarySearchTree{
    private:
        // STRUCTURE OF NODE
        struct Node {
            int val;
            struct Node *right, *left;
            Node(int _val) : val(_val), right(0x0), left(0x0) {};
            ~Node(){};
        };

        // DECLARATIVES
        Node *root = 0x0;
        int size = 0;

        // PRIV INSERT NODE RECURSIVELY
        void insert_rec_priv(Node **root, int val){
            if (*root == 0x0){
                Node *_t = new Node(val);
                *root = _t;
                return;
            } else if (val < (*root)->val){
                insert_rec_priv(&((*root)->left), val);
            } else if (val > (*root)->val){
                insert_rec_priv(&((*root)->right), val);
            }
        }

        // PRIV DELETE TREE RECURSIVELY
        void clean(Node *root){
            if(root == 0x0) return;
            clean(root->left);
            clean(root->right);
            delete root;
        }
        
        // PRIV RECURSIVE TREE TRAVERSAL ALGORITHMS
        void preorder_rec_priv(Node *root){
            if(root == 0x0) return;
            printf("%5d", root->val);
            preorder_rec_priv(root->left);
            preorder_rec_priv(root->right);
        }

        void inorder_rec_priv(Node *root){
            if(root == 0x0) return;
            inorder_rec_priv(root->left);
            printf("%5d", root->val);
            inorder_rec_priv(root->right);
        }

        void postorder_rec_priv(Node *root){
            if(root == 0x0) return;
            postorder_rec_priv(root->left);
            postorder_rec_priv(root->right);
            printf("%5d", root->val);
        }

        // PRIV COUNTING LEAF NODES RECURSIVELY
        int count_leaf_rec_priv(Node *root){
            if (root == 0x0) return 0;
            if (root->left == 0x0 && root->right == 0x0)
                return 1;
            return count_leaf_rec_priv(root->left) + count_leaf_rec_priv(root->right);
        }

        // PRIV COUNTING NON-LEAF NODES RECURSIVELY
        int count_non_leaf_rec_priv(Node *root){
            if (root == 0x0) return 0;
            if (root->left == 0x0 && root->right == 0x0)
                return 0;
            return 1 + count_non_leaf_rec_priv(root->left) + count_non_leaf_rec_priv(root->right);
        }

        // CHECK FOR SAME BST
        friend bool check_bst_rec_priv(Node *r1, Node *r2){
            if(r1 == 0x0 && r2 == 0x0) 
                return true;
            else if (r1 == 0x0 || r2 == 0x0) 
                return false;
            else if (r1->val == r2->val)
                return check_bst_rec_priv(r1->left, r2->left) && check_bst_rec_priv(r1->right, r2->right);
            return false;
        }

    public:
        // CONSTRUCTOR 
        BinarySearchTree(){}

        // DESTRUCTOR
        ~BinarySearchTree(){
            clean(root);
            root = 0x0;
            size = 0;
        }

        // INSERT NODE ITERATIVELY
        void insert_iter(int val){
            Node *_t = new Node(val);
            Node **ptr = &root;
            while(*ptr != 0x0){
                if (val < (*ptr)->val)
                    ptr = &((*ptr)->left) ;
                else 
                    ptr = &((*ptr)->right) ;
            }   *ptr = _t;
            size++;
        }

        // INSERT NODE RECURSIVELY
        void insert_rec(int val){
            insert_rec_priv(&root, val);
            size++;
        }

        // SEARCHING 
        bool search(int target){
            Node *ptr = root;
            while(ptr != 0x0 && ptr->val != target){
                if(target < ptr->val)
                    ptr = ptr->left;
                else if (target > ptr->val)
                    ptr = ptr->right;
            }   return ptr != 0x0;
        }

        // COUNTING LEAF NODE
        int count_leaf(){
            return count_leaf_rec_priv(root);
        }

        // 
        int count_non_leaf(){
            return count_non_leaf_rec_priv(root);
        }

        // RECURSIVE TREE TRAVERSAL
        void traverse_rec(){
            if (root == 0x0) {
                cout << "No elements in the BST!\n";
                return;
            }
            printf("[%p] %-15s", root, "Preorder : ");
            preorder_rec_priv(root);
            cout << endl;

            printf("[%p] %-15s", root, "Postorder : ");
            postorder_rec_priv(root);
            cout << endl;

            printf("[%p] %-15s", root, "Inorder : ");
            inorder_rec_priv(root);
            cout << endl;
        }
        
        // CHECK FOR SAME BST
        friend bool check_bst(BinarySearchTree *n1, BinarySearchTree *n2){
            return check_bst_rec_priv(n1->root, n2->root);
        }

};

void test_1(){ // viii. Count the non-leaf nodes and leaf nodes
    srand(time(0));
    BinarySearchTree n1;
    int val;
    printf("%-10s", "Insert ->");
    for(int i = 0; i < 10; i++){
        val = rand() % 100;
        printf(" %5d", val);
        n1.insert_iter(val);
    }   cout << endl;
    n1.traverse_rec();
    cout << "Number of leaf nodes : " << n1.count_leaf() << endl;
    cout << "Number of non-leaf nodes : " << n1.count_non_leaf() << endl;
}

void test_2(){ // iv. Search a no. in BST
    BinarySearchTree n1;
    n1.traverse_rec();
    n1.insert_iter(10);
    n1.traverse_rec();
    printf(n1.search(10) ? "target found!\n": "target not found!\n" );
    printf(n1.search(11) ? "target found!\n": "target not found!\n" );
}

void test_3(){ // xi. Check whether two BSTs are equal or not
    BinarySearchTree n1, n2, n3, n4;
    for(int i = 0; i <= 10; i++){
        n1.insert_rec(i);
        n2.insert_rec(i);
        if (i<5)
            n3.insert_rec(i);
    }
    n1.traverse_rec();
    n2.traverse_rec();
    n3.traverse_rec();
    cout << "n1 and n2 are " << (check_bst(&n1, &n2) ? "same" : "not same" ) << endl;
    cout << "n1 and n3 are " << (check_bst(&n1, &n3) ? "same" : "not same" ) << endl;
    cout << "n1 and n4 are " << (check_bst(&n1, &n4) ? "same" : "not same" ) << endl;
    cout << "n2 and n3 are " << (check_bst(&n2, &n3) ? "same" : "not same" ) << endl;
    cout << "n2 and n4 are " << (check_bst(&n2, &n4) ? "same" : "not same" ) << endl;
    cout << "n3 and n4 are " << (check_bst(&n3, &n4) ? "same" : "not same" ) << endl;
}

int main(void){
    test_1();
    test_2();
    test_3();
    return 0;
}

/*
   Insert ->     33    41    17    58    96    63    32    56    98    51
   [0x5635df1242c0] Preorder :        33   17   32   41   58   56   51   96   63   98
   [0x5635df1242c0] Postorder :       32   17   51   56   63   98   96   58   41   33
   [0x5635df1242c0] Inorder :         17   32   33   41   51   56   58   63   96   98
   Number of leaf nodes : 4
   Number of non-leaf nodes : 6
   No elements in the BST!
   [0x5635df124340] Preorder :        10
   [0x5635df124340] Postorder :       10
   [0x5635df124340] Inorder :         10
   target found!
   target not found!
   [0x5635df124340] Preorder :         0    1    2    3    4    5    6    7    8    9   10
   [0x5635df124340] Postorder :       10    9    8    7    6    5    4    3    2    1    0
   [0x5635df124340] Inorder :          0    1    2    3    4    5    6    7    8    9   10
   [0x5635df1243c0] Preorder :         0    1    2    3    4    5    6    7    8    9   10
   [0x5635df1243c0] Postorder :       10    9    8    7    6    5    4    3    2    1    0
   [0x5635df1243c0] Inorder :          0    1    2    3    4    5    6    7    8    9   10
   [0x5635df124360] Preorder :         0    1    2    3    4
   [0x5635df124360] Postorder :        4    3    2    1    0
   [0x5635df124360] Inorder :          0    1    2    3    4
   n1 and n2 are same
   n1 and n3 are not same
   n1 and n4 are not same
   n2 and n3 are not same
   n2 and n4 are not same
   n3 and n4 are not same
 *
 */

