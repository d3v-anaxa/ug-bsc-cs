#include "bst.h"

/* Driver's code*/
int main(){
    Node* root1 = NULL;
    root1 = create(4);
    root1->left = create(2);
    root1->right = create(5);
    root1->left->left = create(1);
    root1->left->right = create(3);
    root1->right->right = create(6);


    Node* root2 = create(50);
    root2->left = create(40);
    root2->right = create(60);
    root2->left->left = create(30);
    root2->left->right = create(45);
    root2->right->left = create(55);
    root2->right->right = create(80);

    printf("[ROOT1]\n");
    traverse(root1);

    printf("[ROOT2]\n");
    traverse(root2);

    clean(root1);
    clean(root2);
    return 0;
}

/*OUTPUT 
  [ROOT1]

       4
      / \
     2   5
    / \   \
   1   3   6

  preorder ->  4 2 1 3 5 6
  inorder ->  1 2 3 4 5 6
  postorder ->  1 3 2 6 5 4

  [ROOT2]

        50
       /  \
      /    \
     40    60
    / \    / \
   /  45  /   80
  30     55

  preorder ->  50 40 30 45 60 55 80
  inorder ->  30 40 45 50 55 60 80
  postorder ->  30 45 40 55 80 60 50
*/

