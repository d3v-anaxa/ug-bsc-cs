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

    public:
        CircularLinkedList(){};
        ~CircularLinkedList(){
            clean();
        };

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
};

int main(void){
    CircularLinkedList<int> cll;

    // ADD TO FRONT
    for (int i = 0; i < 20; i++){
        cll.addToFront(1 << i);
    }   cll.display();

    // REVERSAL
    cll.reverse();
    cll.display();

    // RM FROM END
    for (int i = 0; i < 20; i++){
        cll.rmFromEnd();
    }   cll.display();

    // ADD TO END
    for (int i = 0; i < 20; i++){
        cll.addToEnd(1 << 31 >> i);
    }   cll.display();

    // SEARCH
    cout << "Target " << -4096 << " " << (cll.search(-4096) == -1 ? "not" : "") << " found!\n";
    cout << "Target " << 4095 << " " << (cll.search(4095) == -1 ? "not" : "") << " found!\n";

    // RM FROM FRONT
    for (int i = 0; i < 20; i++){
        cll.rmFromFront();
    }   cll.display();
    return 0;
}
