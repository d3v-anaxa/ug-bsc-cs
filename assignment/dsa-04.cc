// Implement Doubly Linked List using templates. 
// Include functions for insertion, deletion
// and search of a number, reverse the lis

#include <iostream>

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
    public:
        DoublyLinkedList(){
            cout << "[DOUBLY LINKED LIST INIT]" << endl;
        };
        ~DoublyLinkedList(){
            clean();
            cout << "[DOUBLY LINKED LIST DESTROYED]" << endl;
        };

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
};

int main(void){
    // INIT DOUBLY LINKED LIST OBJECT
    DoublyLinkedList<int> dll;

    // ADD TO FRONT
    for (int i = 0; i < 1000; i++){
        dll.addToFront(i);
    }   dll.display();

    // REMOVE FROM END
    for (int i = 0; i < 1000; i++){
        dll.rmFromEnd();
    }   dll.display();

    // ADD TO END
    for (int i = 0; i < 1000; i++){
        dll.addToEnd(i*i);
    }   dll.display();

    // REVERSAL 
    dll.reverse();
    dll.display();

    // SEARCH
    dll.search(1024);

    // REMOVE FROM FRONT
    for (int i = 0; i < 1000; i++){
        dll.rmFromFront();
    }   dll.display();

    return 0;
}
