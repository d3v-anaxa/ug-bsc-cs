// Implement Linked List using templates. Include functions for insertion, deletion and
// search of a number, reverse the list and concatenate two linked lists (include a function
// and also overload operator +).

#include <cstddef>
#include <iostream>
using namespace std;

template<typename T>
class LinkedList{
    public:
        // CONSTUCTOR
        LinkedList(){
            head = new Node();
        }
        LinkedList(T val){
            head = new Node{ val, nullptr };
            _size++;
        }

        // INSERTION
        void insert(T val){
            Node* ptr = head;
            head = new Node{ val, ptr };
            _size++;
        }

        // READ
        void display(){
            if(_size == 0) {
                cout << "Empty list!\n";
                return;
            }
            Node* ptr = head;
            cout << "List elements[" << _size << "] -> ";
            if (ptr == NULL) {
                cout << endl;
                return;
            }
            while(ptr != NULL ){
                cout << ptr->val << " ";
                ptr = ptr->next;
            } cout << endl;
        }

        // SEARCH
        void search(T target){
            int counter = 0;
            Node* ptr = head;
            while(ptr != NULL){
                if(ptr->val == target) {
                    cout << "Target |"<< target <<"| found at index-" << counter << endl;
                    return;
                }
                counter++;
                ptr = ptr->next;
            }
            cout << "Target not found!\n";
        }

        // DELETION
        void remove(){
            if(head == NULL) {
                cout << "EMPTY LIST\n";
                return;
            }

            Node* ptr = head;
            head = head->next;
            cout << "Removed value -> " << ptr->val << endl;
            delete ptr;
            _size--;
        }

        // DESTRUCTOR
        ~LinkedList(){
            clearList(head);
            cout << "Object destroyed successfully!\n";
        }

        // REVERSAL
        void rev(){
            if (head == nullptr || head->next == nullptr) {
                return;
            }
            revRecurse(nullptr, head);
            cout << "Reversed successfully!\n";
        }

        // **OVERLOADED OPERATOR**
        /*
        LinkedList<T> operator + (LinkedList ll){
            LinkedList<T> _t;
            Node* ptr = head;
            while(ptr->next != NULL){
                _t.insert(ptr->val);
                ptr = ptr->next;
            }
            ptr = ll.head;
            while(ptr->next != NULL){
                _t.insert(ptr->val);
                ptr = ptr->next;
            }
            return _t;
        }
        */ // CONCEPT NOT CLEAR YET

    private:
        typedef struct Node {
            T val;
            struct Node* next;
        } Node;
        unsigned int _size = 0;
        Node* head = NULL;

        // MEM CLEAR
        void clearList(Node* head){
            if(head == NULL) return;
            clearList(head->next);
            delete head;
        }

        // RECURSIVE REVERSAL FUNC.
        void revRecurse(Node* prev, Node* current){
            if (current == nullptr){
                head = prev;
                return;
            }
            revRecurse(current, current->next);
            current->next = prev;
        }
};

int main(void){
    LinkedList<int> ll(1);
    LinkedList<int> ll2(2);
    LinkedList<int> ll3(3);
    ll.insert(10);
    ll.display();
    ll.insert(11);
    ll.display();
    ll.insert(12);
    ll.display();
    ll.search(11);
    ll.remove();
    ll.display();

    
    ll2.insert(20);
    ll2.display();
    ll2.insert(21);
    ll2.display();
    ll2.insert(22);
    ll2.display();
    ll2.search(22);
    ll2.remove();
    ll2.display();
    ll2.rev();
    ll2.display();

    ll3.display();
    return 0;
}

// Output
// List elements -> 10
// List elements -> 11 10
// List elements -> 12 11 10
// Target |11| found at index-1
// Removed value -> 12
// List elements -> 11 10
