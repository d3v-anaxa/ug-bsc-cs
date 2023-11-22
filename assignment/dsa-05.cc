/*
   Implement Circular Linked List using templates. Include functions for insertion,
   deletion and search of a number, reverse the list
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

/*
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 10
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 1
   Enter value : 20
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : 50
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 2
   Enter value : 90
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   Elements [4] [HEAD : 0x557472ec0af0] [TAIL : 0x557472ec0b30]  20 10 50 90
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 6
   Reversed successfully!
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 7
   Elements [4] [HEAD : 0x557472ec0b30] [TAIL : 0x557472ec0af0]  90 50 10 20
   Circular Singly linked list operations!
   [1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
   Enter  choice : 4
Removed : 90
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 5
Removed : 20
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 7
Elements [2] [HEAD : 0x557472ec0b10] [TAIL : 0x557472ec0ad0]  50 10
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 3
Enter value : 10
Target found!
Circular Singly linked list operations!
[1. Add to head, 2. Add to tail, 3. Search, 4. Remove from head, 5. Remove from tail, 6. Reverse list, 7. Display]
Enter  choice : 10
*/
