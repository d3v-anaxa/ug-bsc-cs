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

/*
 * OUTPUT
==100775== Memcheck, a memory error detector
==100775== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==100775== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==100775== Command: ./a.out
==100775== 
Elements [20] [HEAD : 0x4dfd670] [TAIL : 0x4dfd080]  524288 262144 131072 65536 32768 16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
Reversed successfully!
Elements [20] [HEAD : 0x4dfd080] [TAIL : 0x4dfd670]  1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288
Removed : 524288
Removed : 262144
Removed : 131072
Removed : 65536
Removed : 32768
Removed : 16384
Removed : 8192
Removed : 4096
Removed : 2048
Removed : 1024
Removed : 512
Removed : 256
Removed : 128
Removed : 64
Removed : 32
Removed : 16
Removed : 8
Removed : 4
Removed : 2
Removed : 1
No element to display!
Elements [0] [HEAD : 0] [TAIL : 0] 
Elements [20] [HEAD : 0x4dfe700] [TAIL : 0x4dfecf0]  -2147483648 -1073741824 -536870912 -268435456 -134217728 -67108864 -33554432 -16777216 -8388608 -4194304 -2097152 -1048576 -524288 -262144 -131072 -65536 -32768 -16384 -8192 -4096
Target -4096  found!
Target 4095 not found!
Removed : -2147483648
Removed : -1073741824
Removed : -536870912
Removed : -268435456
Removed : -134217728
Removed : -67108864
Removed : -33554432
Removed : -16777216
Removed : -8388608
Removed : -4194304
Removed : -2097152
Removed : -1048576
Removed : -524288
Removed : -262144
Removed : -131072
Removed : -65536
Removed : -32768
Removed : -16384
Removed : -8192
Removed : -4096
No element to display!
Elements [0] [HEAD : 0] [TAIL : 0] 
==100775== 
==100775== HEAP SUMMARY:
==100775==     in use at exit: 0 bytes in 0 blocks
==100775==   total heap usage: 42 allocs, 42 frees, 78,464 bytes allocated
==100775== 
==100775== All heap blocks were freed -- no leaks are possible
==100775== 
==100775== For lists of detected and suppressed errors, rerun with: -s
==100775== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
