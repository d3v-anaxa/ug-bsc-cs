/*
   Implement Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.
   */

/* ALGO
   1. Creating a Singly Linked List:
   1.1. Define a class 'Node' with a variable 'data' to store the node's data and a variable 'next' to store the reference to the next node.
   1.2. Define a class 'LinkedList' with a variable 'head' to store the reference to the first node in the list.

   2. Adding a Node to the Head:
   2.1. Create a new 'Node' with the given data.
   2.2. Set the 'next' of the new node to the current 'head' of the list.
   2.3. Update the 'head' of the list to the new node.

   3. Adding a Node to the Tail:
   3.1. Create a new 'Node' with the given data.
   3.2. If the list is empty, set the 'head' of the list to the new node.
   3.3. Otherwise, traverse the list to find the last node and set its 'next' to the new node.

   4. Removing a Node from the Head:
   4.1. If the list is not empty, update the 'head' of the list to the 'next' of the current 'head'.

   5. Removing a Node from the Tail:
   5.1. If the list is not empty, traverse the list to find the second last node.
   5.2. Set the 'next' of the second last node to null.

   6. Reversing the Linked List:
   6.1. Initialize three pointers: 'prev' to null, 'current' to the 'head' of the list, and 'next'.
   6.2. While 'current' is not null:
   6.2.1. Set 'next' to the 'next' of 'current'.
   6.2.2. Set the 'next' of 'current' to 'prev'.
   6.2.3. Move 'prev' and 'current' one step forward.
   6.3. Set the 'head' of the list to 'prev'.

   7. Searching an Element in the Linked List:
   7.1. Initialize a variable 'current' to the 'head' of the list.
   7.2. While 'current' is not null:
   7.2.1. If the 'data' of 'current' is equal to the element to be searched, return true.
   7.2.2. Move 'current' one step forward.
   7.3. If the loop completes without finding the element, return false.

*/

#include <bits/stdc++.h>
using namespace std;

#define CLEAN   "\033[0;0m"
#define BLACK   "\033[30;01m"
#define RED     "\033[31;01m"
#define GREEN   "\033[32;01m"
#define YELLOW  "\033[33;01m"
#define BLUE    "\033[34;01m"
#define PINK    "\033[35;01m"
#define TEAL    "\033[36;01m"
#define WHITE   "\033[37;01m"

template<typename T>
class LinkedList{
    private:
        // STRUCTURE OF NODE
        typedef struct Node {
            T val;
            struct Node* next;
        } Node;

        // DECLARATIVES
        Node* head = 0x0;
        int length = 0;

        // MEM CLEAR
        void clean (Node* head){
            if(head == 0x0) return;
            Node *prev = 0x0, *curr = head;
            while(curr != 0x0){
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }

        // INSERT TO HEAD
        void addH(T val){
            Node *ptr = head;
            head = new Node{val, ptr};
            cout 
                << GREEN
                << "List +>> " << val 
                << CLEAN
                << endl;
            length++;
        }

        // INSERT TO TAIL
        void addT(T val){
            if (head == 0x0){
                head = new Node{val, 0x0};
            } else {
                Node *_t = new Node{val, 0x0}, *ptr = head;
                while(ptr->next != 0x0){
                    ptr = ptr->next;
                }   ptr->next = _t;
            }   length++;
            cout 
                << GREEN
                << "List <<+ " << val 
                << CLEAN
                << endl;
        }

        // SEARCH
        bool search(T target){
            Node *ptr = head;
            while(ptr != 0x0){
                if (ptr->val == target) return true;
                ptr = ptr->next;
            }   return false;
        }

        // DELETE FROM HEAD
        void rmH(){
            if (head == 0x0) return;
            Node *ptr = head;
            head = head->next;
            delete ptr;
            length--;
            cout 
                << RED
                << "Deleted Node [-<<]" 
                << CLEAN
                << endl;
        }

        // DELETE FROM TAIL
        void rmT(){
            if (head == 0x0) return;
            Node *prev = head, 
                 *curr = head;
            while (curr->next != 0x0){
                prev = curr;
                curr = curr->next;
            }
            if (curr == head){
                head = 0x0;
            } else {
                prev->next = 0x0;
            }   delete curr;
            length--;
            cout 
                << RED
                << "Deleted Node [>>-]" 
                << CLEAN
                << endl;
        }

        // REVERSE THE LIST
        void reverse(){
            if(length < 2) return;
            Node *prev = 0x0, *curr = head, *next = 0x0;
            while(curr != 0x0){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }   head = prev;
            cout 
                << TEAL
                << "List reversed!"
                << CLEAN
                << endl;
        }

    public:
        // CONSTRUCTOR
        LinkedList(){}

        // DESTRUCTOR
        ~LinkedList(){
            clean(head);
            head = 0x0;
               cout 
               << RED
               << "[LIST CLEANED]\n"
               << CLEAN;
            length = 0;
        }

        // Display
        int display(){
            cout << YELLOW;
            if (length < 1) {
                cout 
                    << "Empty list!"
                    << CLEAN
                    << endl;
                return length;
            }
            Node *ptr = head;
            cout << ">> ";
            while(ptr != 0x0){
                cout << " " << ptr->val;
                ptr = ptr->next;
            }   
            cout 
                << CLEAN
                << endl;
            return length;
        }

        // MENU
        bool menu(){
            T value = 0;
            int option = 0;
            cout 
                << BLUE
                << "Linked List Operations!\n"
                << "[1: insert to head, "
                << "2: insert to tail, "
                << "3: search, "
                << "4: remove from head, "
                << "5: remove from tail, "
                << "6: reverse list, "
                << "7: display list]"
                << "\nEnter choice : ";
            cin >> option;
            cout << WHITE;
            switch (option){
                case 1: cout << "Enter value : " && cin >> value;
                        this->addH(value);
                        break;
                case 2: cout << "Enter value : " && cin >> value;
                        this->addT(value);
                        break;
                case 3: cout << "Enter value : " && cin >> value;
                        cout 
                            << YELLOW
                            << (this->search(value) ? "Target found" : "Target not found") 
                            << CLEAN
                            << endl;

                        break;
                case 4: this->rmH();
                        break;
                case 5: this->rmT();
                        break;
                case 6: this->reverse();
                        break;
                case 7: this->display();
                        break;
                default:
                        cout << CLEAN;
                    return false;
            }
            cout << CLEAN;
            return true;
        }

};

int main(void){
    LinkedList<int> l1;
    bool cont = true;
    cout << GREEN << "[LINKED LIST]\n" << endl;
    do {
        cont = l1.menu();
    } while(cont);
    return 0;
}

/* OUTPUT
   [LINKED LIST]
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 10
   List +>> 10
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 2
   Enter value : -100
   List <<+ -100
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 33
   List +>> 33
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 2
   Enter value : 55
   List <<+ 55
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  33 10 -100 55
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 4
   Deleted Node [-<<]
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 5
   Deleted Node [>>-]
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 6
   List reversed!
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  -100 10
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 10
   [LIST CLEANED]
   */

/* OUTPUT
   [LINKED LIST]
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 12
   List +>> 12
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 15
   List +>> 15
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : -10
   List +>> -10
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  -10 15 12
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 6
   List reversed!
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  12 15 -10
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 3
   Enter value : -10
   Target found
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 5
   Deleted Node [>>-]
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  12 15
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 10
   [LIST CLEANED]
   */
