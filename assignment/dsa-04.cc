/*
  Implement Doubly Linked List using templates. 
  Include functions for insertion, deletion and search of a number, reverse the list.
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
                default:
                    return false;
            }
            return true;
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

/*
   [DOUBLY LINKED LIST INIT]
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [2] :  10 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 20
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : 30
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [4] :  20 10 10 30
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 6
   Reversed!
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [4] :  30 10 10 20
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 3
   Enter value : 5
   Target -> 5 not found!
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 5
   Removed [TAIL] : 20
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   List elements [3] :  30 10 10
   Doubly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 10
   [DOUBLY LINKED LIST DESTROYED]
   */
