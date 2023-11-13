/*
   Perform Stack operations using Linked List implementation
*/

#include <iostream>
#define SIZE 256

using namespace std;
template<typename T>
class Stack{
    private:
        struct Node{
            T val;
            struct Node* next;
            Node(T _val, struct Node *_next) : val(_val), next(_next) {};
        };
        int curr_length = 0;
        int max_length = 0;
        Node *head = 0x0;
        
        void clean(){
            Node *prev = 0x0, *curr = head;
            while(curr != 0x0){
                prev = curr;
                curr = curr->next;
                delete prev;
            }   head = 0x0;
        }

    public:
        Stack(int maxLen){
            cout << "[STACK INIT]" << endl;
            max_length = maxLen;
        }

        ~Stack(){
            clean();
            curr_length = 0;
            cout << "[STACK DESTROYED]" << endl;
        }

        void push(T val){
            if (curr_length == max_length) {
                cout << "STACK OVERFLOW!\n";
                return;
            }
            Node *_t = new Node(val, head);
            head = _t;
            curr_length++;
        }

        void pop(){
            if (curr_length == 0){
                cout << "Empty stack!\n";
                return ;
            }
            Node *_t = head;
            head = head->next;
            curr_length--;
            cout << "POP -> " << _t->val << endl;
            delete _t;
        }

        void display(){
            cout 
                << "Stack ["
                << curr_length << "/" << max_length
                << "] ";
            Node *curr = head;
            while(curr != 0x0){
                cout << " " << curr->val;
                curr = curr->next;
            }   cout << endl;
        }
};

int main(void){
    Stack<int> head(SIZE);

    // PUSH
    for(int i = 0; i <= SIZE; i++){
        head.push(i*i);
    }   head.display();

   // POP
     for(int i = 10; i < SIZE; i++){
         head.pop();
    }   head.display();

}

/*
 * OUTPUT
==108448== Memcheck, a memory error detector
==108448== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==108448== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==108448== Command: ./a.out
==108448== 
[STACK INIT]
STACK OVERFLOW!
Stack [256/256]  65025 64516 64009 63504 63001 62500 62001 61504 61009 60516 60025 59536 59049 58564 58081 57600 57121 56644 56169 55696 55225 54756 54289 53824 53361 52900 52441 51984 51529 51076 50625 50176 49729 49284 48841 48400 47961 47524 47089 46656 46225 45796 45369 44944 44521 44100 43681 43264 42849 42436 42025 41616 41209 40804 40401 40000 39601 39204 38809 38416 38025 37636 37249 36864 36481 36100 35721 35344 34969 34596 34225 33856 33489 33124 32761 32400 32041 31684 31329 30976 30625 30276 29929 29584 29241 28900 28561 28224 27889 27556 27225 26896 26569 26244 25921 25600 25281 24964 24649 24336 24025 23716 23409 23104 22801 22500 22201 21904 21609 21316 21025 20736 20449 20164 19881 19600 19321 19044 18769 18496 18225 17956 17689 17424 17161 16900 16641 16384 16129 15876 15625 15376 15129 14884 14641 14400 14161 13924 13689 13456 13225 12996 12769 12544 12321 12100 11881 11664 11449 11236 11025 10816 10609 10404 10201 10000 9801 9604 9409 9216 9025 8836 8649 8464 8281 8100 7921 7744 7569 7396 7225 7056 6889 6724 6561 6400 6241 6084 5929 5776 5625 5476 5329 5184 5041 4900 4761 4624 4489 4356 4225 4096 3969 3844 3721 3600 3481 3364 3249 3136 3025 2916 2809 2704 2601 2500 2401 2304 2209 2116 2025 1936 1849 1764 1681 1600 1521 1444 1369 1296 1225 1156 1089 1024 961 900 841 784 729 676 625 576 529 484 441 400 361 324 289 256 225 196 169 144 121 100 81 64 49 36 25 16 9 4 1 0
POP -> 65025
POP -> 64516
POP -> 64009
POP -> 63504
POP -> 63001
POP -> 62500
POP -> 62001
POP -> 61504
POP -> 61009
POP -> 60516
POP -> 60025
POP -> 59536
POP -> 59049
POP -> 58564
POP -> 58081
POP -> 57600
POP -> 57121
POP -> 56644
POP -> 56169
POP -> 55696
POP -> 55225
POP -> 54756
POP -> 54289
POP -> 53824
POP -> 53361
POP -> 52900
POP -> 52441
POP -> 51984
POP -> 51529
POP -> 51076
POP -> 50625
POP -> 50176
POP -> 49729
POP -> 49284
POP -> 48841
POP -> 48400
POP -> 47961
POP -> 47524
POP -> 47089
POP -> 46656
POP -> 46225
POP -> 45796
POP -> 45369
POP -> 44944
POP -> 44521
POP -> 44100
POP -> 43681
POP -> 43264
POP -> 42849
POP -> 42436
POP -> 42025
POP -> 41616
POP -> 41209
POP -> 40804
POP -> 40401
POP -> 40000
POP -> 39601
POP -> 39204
POP -> 38809
POP -> 38416
POP -> 38025
POP -> 37636
POP -> 37249
POP -> 36864
POP -> 36481
POP -> 36100
POP -> 35721
POP -> 35344
POP -> 34969
POP -> 34596
POP -> 34225
POP -> 33856
POP -> 33489
POP -> 33124
POP -> 32761
POP -> 32400
POP -> 32041
POP -> 31684
POP -> 31329
POP -> 30976
POP -> 30625
POP -> 30276
POP -> 29929
POP -> 29584
POP -> 29241
POP -> 28900
POP -> 28561
POP -> 28224
POP -> 27889
POP -> 27556
POP -> 27225
POP -> 26896
POP -> 26569
POP -> 26244
POP -> 25921
POP -> 25600
POP -> 25281
POP -> 24964
POP -> 24649
POP -> 24336
POP -> 24025
POP -> 23716
POP -> 23409
POP -> 23104
POP -> 22801
POP -> 22500
POP -> 22201
POP -> 21904
POP -> 21609
POP -> 21316
POP -> 21025
POP -> 20736
POP -> 20449
POP -> 20164
POP -> 19881
POP -> 19600
POP -> 19321
POP -> 19044
POP -> 18769
POP -> 18496
POP -> 18225
POP -> 17956
POP -> 17689
POP -> 17424
POP -> 17161
POP -> 16900
POP -> 16641
POP -> 16384
POP -> 16129
POP -> 15876
POP -> 15625
POP -> 15376
POP -> 15129
POP -> 14884
POP -> 14641
POP -> 14400
POP -> 14161
POP -> 13924
POP -> 13689
POP -> 13456
POP -> 13225
POP -> 12996
POP -> 12769
POP -> 12544
POP -> 12321
POP -> 12100
POP -> 11881
POP -> 11664
POP -> 11449
POP -> 11236
POP -> 11025
POP -> 10816
POP -> 10609
POP -> 10404
POP -> 10201
POP -> 10000
POP -> 9801
POP -> 9604
POP -> 9409
POP -> 9216
POP -> 9025
POP -> 8836
POP -> 8649
POP -> 8464
POP -> 8281
POP -> 8100
POP -> 7921
POP -> 7744
POP -> 7569
POP -> 7396
POP -> 7225
POP -> 7056
POP -> 6889
POP -> 6724
POP -> 6561
POP -> 6400
POP -> 6241
POP -> 6084
POP -> 5929
POP -> 5776
POP -> 5625
POP -> 5476
POP -> 5329
POP -> 5184
POP -> 5041
POP -> 4900
POP -> 4761
POP -> 4624
POP -> 4489
POP -> 4356
POP -> 4225
POP -> 4096
POP -> 3969
POP -> 3844
POP -> 3721
POP -> 3600
POP -> 3481
POP -> 3364
POP -> 3249
POP -> 3136
POP -> 3025
POP -> 2916
POP -> 2809
POP -> 2704
POP -> 2601
POP -> 2500
POP -> 2401
POP -> 2304
POP -> 2209
POP -> 2116
POP -> 2025
POP -> 1936
POP -> 1849
POP -> 1764
POP -> 1681
POP -> 1600
POP -> 1521
POP -> 1444
POP -> 1369
POP -> 1296
POP -> 1225
POP -> 1156
POP -> 1089
POP -> 1024
POP -> 961
POP -> 900
POP -> 841
POP -> 784
POP -> 729
POP -> 676
POP -> 625
POP -> 576
POP -> 529
POP -> 484
POP -> 441
POP -> 400
POP -> 361
POP -> 324
POP -> 289
POP -> 256
POP -> 225
POP -> 196
POP -> 169
POP -> 144
POP -> 121
POP -> 100
Stack [10/256]  81 64 49 36 25 16 9 4 1 0
[STACK DESTROYED]
==108448== 
==108448== HEAP SUMMARY:
==108448==     in use at exit: 0 bytes in 0 blocks
==108448==   total heap usage: 258 allocs, 258 frees, 81,920 bytes allocated
==108448== 
==108448== All heap blocks were freed -- no leaks are possible
==108448== 
==108448== For lists of detected and suppressed errors, rerun with: -s
==108448== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */
