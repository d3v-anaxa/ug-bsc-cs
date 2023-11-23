/*
  Implement Doubly Linked List using templates. 
  Include functions for insertion, deletion and search of a number, reverse the list.
*/

/* ALGO
   1. Creating a Doubly Linked List:
   1.1. Define a class 'Node' with a variable 'data' to store the node's data, a variable 'next' to store the reference to the next node, and a variable 'prev' to store the reference to the previous node.
   1.2. Define a class 'LinkedList' with a variable 'head' to store the reference to the first node in the list.

   2. Adding a Node to the Head:
   2.1. Create a new 'Node' with the given data.
   2.2. If the list is not empty, set the 'prev' of the current 'head' to the new node.
   2.3. Set the 'next' of the new node to the current 'head' of the list.
   2.4. Update the 'head' of the list to the new node.

   3. Adding a Node to the Tail:
   3.1. Create a new 'Node' with the given data.
   3.2. If the list is empty, set the 'head' of the list to the new node.
   3.3. Otherwise, traverse the list to find the last node, set its 'next' to the new node, and the 'prev' of the new node to the last node.

   4. Removing a Node from the Head:
   4.1. If the list is not empty, update the 'head' of the list to the 'next' of the current 'head' and set the 'prev' of the new 'head' to null.

   5. Removing a Node from the Tail:
   5.1. If the list is not empty, traverse the list to find the second last node.
   5.2. Set the 'next' of the second last node to null.

   6. Reversing the Linked List:
   6.1. Initialize three pointers: 'prev' to null, 'current' to the 'head' of the list, and 'next'.
   6.2. While 'current' is not null:
   6.2.1. Set 'next' to the 'next' of 'current'.
   6.2.2. Set the 'next' of 'current' to 'prev' and the 'prev' of 'current' to 'next'.
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

template<typename T>
class DoublyLinkedList{
    private:
        struct Node {
            T val;
            struct Node *prev, *next;
            Node(T _val, struct Node* _prev, struct Node* _next) : val(_val), prev(_prev), next(_next) {};
        };

        Node *head = 0x0,
             *tail = 0x0;
        int length = 0;

        void clean(){
            for (Node *prev = 0x0, *curr = head; curr != 0x0; ){
                prev = curr;
                curr = curr->next;
                delete prev;
            }   
            head = 0x0;
            tail = 0x0;
            length = 0;
        }

        void addToFront(T val){
            Node *_t = new Node(val, 0x0, head);
            if(head == 0x0 && tail == 0x0){
                head = _t;
                tail = _t;
            } else {
                head->prev = _t;
                head = _t;
            }
            length++;
        }

        void addToEnd(T val){
            Node *_t = new Node(val, tail, 0x0);
            if(head == 0x0 && tail == 0x0){
                head = _t;
                tail = _t;
            } else {
                tail->next = _t;
                tail = _t;
            }
            length++;
        }

        void rmFromFront(){
            if (head == 0x0 && tail == 0x0){
                cout << "Empty List!\n";
            } else if (head == tail){
                cout << "Removed [HEAD] : " << head->val << endl;
                delete head;
                head = 0x0;
                tail = 0x0;
                length--;
            } else {
                cout << "Removed [HEAD] : " << head->val << endl;
                Node *_t = head;
                head = head->next;
                head->prev =  0x0;
                delete _t;
                _t = 0x0;
                length--;
            }
        }

        void rmFromEnd(){
            switch (length){
                case 0:
                    cout << "Empty List!\n";
                    break;
                case 1:
                    cout << "Removed [TAIL] : " << tail->val << endl;
                    delete tail;
                    head = 0x0;
                    tail = 0x0;
                    length--;
                    break;
                default:
                    cout << "Removed [TAIL] : " << tail->val << endl;
                    Node *_t = tail;
                    tail = tail->prev;
                    tail->next = 0x0;
                    delete _t;
                    _t = 0x0;
                    length--;
                    break;
            }
        }

        void reverse(){
            Node *tmp = 0x0, *curr = head;
            while(curr != 0x0){
                tmp = curr->next;
                curr->next = curr->prev;
                curr->prev = tmp;
                curr = curr->prev;
            }
            tmp = head;
            head = tail;
            tail = tmp;
            cout << "Reversed!\n";
        }

        void search(T target) const {
            Node *_t = head;
            while(_t != 0x0){
                if (_t->val == target) {
                    cout << "Target -> " << target << " found!\n";
                    return;
                }
                _t = _t->next;
            }
            cout << "Target -> " << target << " not found!\n";
        }

    public:
        DoublyLinkedList(){
            cout << "[DOUBLY LINKED LIST INIT]" << endl;
        };

        ~DoublyLinkedList(){
            clean();
            cout << "[DOUBLY LINKED LIST DESTROYED]" << endl;
        };

        void display() const {
            Node *_t = head;
            if (length == 0){
                cout << "No elements to display!\n";
                return;
            }
            cout << "List elements [" << length << "] : ";
            while (_t != 0x0){
                cout << " " << _t->val;
                _t = _t->next;
            }   cout << endl;
        }

        bool menu(){
            T value;
            int option = 0;
            cout 
                << "Doubly linked list operations!\n"
                << "[1. Add to head, "
                << "2. Add to tail, "
                << "3. Search, "
                << "4. Remove from head, "
                << "5. Remove from tail, "
                << "6. Reverse list, "
                << "7. Display]\n"
                << "Enter  choice : ";
            cin >> option;
            switch (option){
                case 1: cout << "Enter value : " && cin >> value;
                        this->addToFront(value);
                        break;
                case 2: cout << "Enter value : " && cin >> value;
                        this->addToEnd(value);
                        break;
                case 3: cout << "Enter value : " && cin >> value;
                        this->search(value);
                        break;
                case 4: this->rmFromFront();
                        break;
                case 5: this->rmFromEnd();
                        break;
                case 6: this->reverse();
                        break;
                case 7: this->display();
                        break;
                default: return false;
            }   return true;
        }

};

int main(void){
    DoublyLinkedList<int> dll;
    bool cont = true;
    do {
        cont = dll.menu();
    } while(cont);
    return 0;
}

/* OUTPUT
   [DOUBLY LINKED LIST INIT]
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : 200
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [2] :  10 200
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 3
   Enter value : 250
   Target -> 250 not found!
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 4
   Removed [HEAD] : 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 5
   Removed [TAIL] : 200
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   No elements to display!
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 10
   [DOUBLY LINKED LIST DESTROYED]
   */

/* OUTPUT
   [DOUBLY LINKED LIST INIT]
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 41
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 16
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : 25
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : -10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [5] :  -10 16 41 10 25
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 6
   Reversed!
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [5] :  25 10 41 16 -10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 10
   [DOUBLY LINKED LIST DESTROYED]
   */
