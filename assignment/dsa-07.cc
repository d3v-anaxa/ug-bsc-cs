/*
   Perform Stack operations using Array implementation. Use Templates
 */

#include <bits/stdc++.h>

using namespace std;
typedef double T;

template<typename T>
struct Stack {
    T* arr = nullptr;
    int size = 0;
    int bottom = -1;
    int top = -1;

    Stack(){
        do {
            cout << "Enter size : ";
            cin >> size;
            if (size > 0) break;
            else cout << "Invalid size!\n";
        } while(size < 1);

        arr = new T[size];
        if (arr == nullptr) {
            cout << "INIT FAILED!";
            return;
        } else cout << "[STACK INIT]\n";
    }
    ~Stack(){
        delete[] arr;
        cout << "[STACK DESTROYED]\n";
    }

    void push(){
        if (top == size - 1){
            cout << "STACK OVERFLOW DETECTED!\n";
            return;
        }
        top++;
        cout << "Enter element : ";
        cin >> arr[top];
    }

    T pop(){
        if (top == bottom){
            cout << "NOTHING TO POP\n";
            return 0x0;
        }
        top--;
        cout << "Popped element -> " << arr[top+1] << endl;
        return arr[top+1];
    }

    void display() const {
        cout << "Stack elements [" << top+1 << "] : ";
        for(int i = top; i != bottom; i--){
            cout << arr[i] << " ";
        }    cout << endl;
    }

    bool choose(){
        int choice = 0;
        cout 
            << "1. push\n" 
            << "2. pop\n" 
            << "3. display\n"
            << "4. exit\n"
            << "Enter choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                this->push();
                break;
            case 2:
                this->pop();
                break;
            case 3:
                this->display();
                break;
            default:
                cout << "Exit? -> ";
                return false;
        }
        return true;
    }
};



int main(void){
    Stack<T> n1;
    bool cont = true;
    do {
        cont = n1.choose();
    } while (cont);
    return 0;
}

/*
 * OUTPUT
==111624== Memcheck, a memory error detector
==111624== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==111624== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==111624== Command: ./a.out
==111624==
Enter size : 4
[STACK INIT]
1. push
2. pop
3. display
4. exit
Enter choice : 1
Enter element : -10
1. push
2. pop
3. display
4. exit
Enter choice : 1
Enter element : 0
1. push
2. pop
3. display
4. exit
Enter choice : 1
Enter element : 1
1. push
2. pop
3. display
4. exit
Enter choice : 1
Enter element : 10
1. push
2. pop
3. display
4. exit
Enter choice : 1
STACK OVERFLOW DETECTED!
1. push
2. pop
3. display
4. exit
Enter choice : 3
Stack elements [4] : 10 1 0 -10
1. push
2. pop
3. display
4. exit
Enter choice : 2
Popped element -> 10
1. push
2. pop
3. display
4. exit
Enter choice : 1
Enter element : 100
1. push
2. pop
3. display
4. exit
Enter choice : 3
Stack elements [4] : 100 1 0 -10
1. push
2. pop
3. display
4. exit
Enter choice : 4
Exit? -> [STACK DESTROYED]
==111624==
==111624== HEAP SUMMARY:
==111624==     in use at exit: 0 bytes in 0 blocks
==111624==   total heap usage: 9 allocs, 9 frees, 76,093 bytes allocated
==111624==
==111624== All heap blocks were freed -- no leaks are possible
==111624==
==111624== For lists of detected and suppressed errors, rerun with: -s
==111624== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */
