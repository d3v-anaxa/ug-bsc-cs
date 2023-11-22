// Implement Linked List using templates. Include functions for insertion, deletion and
// search of a number, reverse the list and concatenate two linked lists.

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
    LinkedList<int> ll;
    bool cont = true;
    do {
        cont = ll.menu();
    } while(cont);
    return 0;
}

/* OUTPUT 1 
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 10
   List +>> 10
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 2
   Enter value : -30
   List <<+ -30
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 11
   List +>> 11
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 1
   Enter value : 0
   List +>> 0
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 3
   Enter value : -10
   Target not found
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 3
   Enter value : -30
   Target found
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 5
   Deleted Node [>>-]
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  0 11 10
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 6
   List reversed!
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 7
   >>  10 11 0
   Linked List Operations!
   [1: insert to head, 2: insert to tail, 3: search, 4: remove from head, 5: remove from tail, 6: reverse list, 7: display list]
   Enter choice : 10
   [LIST CLEANED]
   */
