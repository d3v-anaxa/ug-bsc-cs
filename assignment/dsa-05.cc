/*
   Implement Circular Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list
*/

/* ALGO
   1. Define Node structure:
   1.1 Node:
   1.1.1 data
   1.1.2 next

   2. Define CircularSinglyLinkedList class:
   2.1 CircularSinglyLinkedList:
   2.1.1 head

   3. Define methods for CircularSinglyLinkedList class:
   3.1 __init__():
   3.1.1 Initialize head to None

   3.2 add_to_head(data):
   3.2.1 Create a new node with the given data
   3.2.2 If the list is empty, set head to the new node
   3.2.3 Otherwise, set the next of the new node to the current head
   3.2.4 Update head to the new node
   3.2.5 Set the next of the last node to the new head to make it circular

   3.3 add_to_tail(data):
   3.3.1 Create a new node with the given data
   3.3.2 If the list is empty, set head to the new node
   3.3.3 Otherwise, find the last node and set its next to the new node
   3.3.4 Set the next of the new node to the head to make it circular

   3.4 remove_from_head():
   3.4.1 If the list is empty, return an error or do nothing
   3.4.2 If there's only one node, set head to None
   3.4.3 Otherwise, update head to the next of the current head
   3.4.4 Find the last node and set its next to the new head

   3.5 remove_from_tail():
   3.5.1 If the list is empty, return an error or do nothing
   3.5.2 If there's only one node, set head to None
   3.5.3 Otherwise, find the second-to-last node and set its next to the head

   3.6 reverse():
   3.6.1 If the list is empty or has only one node, do nothing
   3.6.2 Initialize three pointers: prev = None, current = head, next_node = None
   3.6.3 Loop through the list until current is None
   3.6.4 Set next_node to the next of current
   3.6.5 Set the next of current to prev
   3.6.6 Move prev to current, current to next_node
   3.6.7 Update head to prev after the loop

   3.7 search(element):
   3.7.1 If the list is empty, return False
   3.7.2 Initialize a pointer current to head
   3.7.3 Loop through the list until current is None
   3.7.4 If the data of current is equal to the element, return True
   3.7.5 Move current to the next node
   3.7.6 If the loop completes without finding the element, return False

 */

#include <iostream>
using namespace std;

template<typename T>
class CircularLinkedList{
    private:
        struct Node{
            T val;
            struct Node *next;
            Node(T _val, struct Node *_next) : val(_val), next(_next) {};
        };

        Node *head = 0x0,
             *tail = 0x0;

        int length = 0;
        void clean(){
            if (head == 0x0){}
            else if (head == head->next){
                delete head;
                head = 0x0;
                length = 0;
            } else {
                Node *prev = 0x0, *curr = head; 
                while (curr != tail){
                    prev = curr;
                    curr = curr->next;
                    delete prev;
                }   delete curr;
                head = 0x0;
                tail = 0x0;
            }
        }

        void addToFront(T val){
            if(head == 0x0){
                Node *_t = new Node(val, 0x0);
                head = _t;
                tail = _t;
                head->next = head;
            } else {
                Node *_t = new Node(val, head);
                head = _t;
                tail->next = head;
            }   length++;
        }

        void addToEnd(T val){
            if(tail == 0x0){
                Node *_t = new Node(val, 0x0);
                tail = _t;
                head = _t;
                tail->next = head;
            } else {
                Node *_t = new Node(val, head);
                tail->next = _t;
                tail = tail->next;
            }   length++;
        }

        void rmFromFront(){
            if (head == 0x0){
                cout << "Empty list!\n";
                return;
            } else if (head == tail){
                cout << "Removed : " << head->val << endl;
                delete head;
                head = 0x0;
                tail = 0x0;
                length = 0;
                return;
            }
            Node *_t = head;
            tail->next = head->next;
            head = head->next;
            cout << "Removed : " << _t->val << endl;
            length--;
            delete _t;
        }

        void rmFromEnd(){
            if (tail == 0x0){
                cout << "Empty list!\n";
                return;
            } else if (head == tail){
                cout << "Removed : " << tail->val << endl;
                delete tail;
                head = 0x0;
                tail = 0x0;
                length = 0;
                return;
            }
            Node *_t = tail,
                 *curr = head;
            while (curr->next != tail){
                curr = curr->next;
            }   
            tail = curr;
            tail->next = head;
            cout << "Removed : " << _t->val << endl;
            delete _t;
            length--;
        }

        int search(T target){
            Node* curr = head;
            for(int i = 0; i < length; i++){
                if(curr->val == target) return i;
                curr = curr->next;
            }   return -1;
        }

        void reverse(){
            if (length < 2) return;
            tail->next = 0x0;
            tail = head;
            Node *prev = 0x0,
                 *curr = head,
                 *next = 0x0;
            while(curr != 0x0){
                next = curr->next;
                curr->next = prev ;
                prev = curr ;
                curr = next;
            } head = prev;
            tail->next = prev;
            cout << "Reversed successfully!\n";
        }

    public:
        CircularLinkedList(){};
        ~CircularLinkedList(){
            clean();
        };

        void display(){
            if (head == 0x0){
                cout << "No element to display!\n";
            }
            cout 
                << "Elements "
                << "[" << length << "] "
                << "[HEAD : " << head << "] "
                << "[TAIL : " << tail << "] ";
            Node *curr = head;
            for(int i = 0; i < length; i++){
                cout << " " << curr->val;
                curr = curr->next;
            }   cout << endl;
        }

        bool menu(){
            T value;
            int option = 0;
            cout 
                << "Circular Singly linked list operations!\n"
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
                        cout << (this->search(value) == -1 ? "Target not found!\n" : "Target found!\n");
                        break;
                case 4: this->rmFromFront();
                        break;
                case 5: this->rmFromEnd();
                        break;
                case 6: this->reverse();
                        break;
                case 7: this->display();
                        break;
                default:
                        return false;
            }
            return true;
        }

};

int main(void){
    CircularLinkedList<int> cll;
    bool cont = true;
    do {
        cont = cll.menu();
    } while(cont);

    return 0;
}

/* OUTPUT
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 1
Enter value : 10
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 2
Enter value : 200
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 1
Enter value : 300
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 2
Enter value : 4000
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 7
Elements [4] [HEAD : 0x5624fee2bb10] [TAIL : 0x5624fee2bb30]  300 10 200 4000
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 6
Reversed successfully!
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 7
Elements [4] [HEAD : 0x5624fee2bb30] [TAIL : 0x5624fee2bb10]  4000 200 10 300
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 4
Removed : 4000
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 5
Removed : 300
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 7
Elements [2] [HEAD : 0x5624fee2baf0] [TAIL : 0x5624fee2bad0]  200 10
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 10
*/

/* OUTPUT
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 10
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : -10
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : 40
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : -40
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 3
   Enter value : 10
   Target found!
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   Elements [4] [HEAD : 0x561c54f47ad0] [TAIL : 0x561c54f47b30]  10 -10 40 -40
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 6
   Reversed successfully!
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   Elements [4] [HEAD : 0x561c54f47b30] [TAIL : 0x561c54f47ad0]  -40 40 -10 10
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 10
   */
