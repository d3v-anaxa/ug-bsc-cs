/*
   Perform Stack operations using Array implementation. Use Templates
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
    private:
        T* arr = nullptr;
        int size = 0;
        int bottom = -1;
        int top = -1;

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

    public:
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

        void display() const {
            cout 
                << "Stack elements [" 
                << top+1 
                << "/"<< size 
                << "] : ";
            for(int i = top; i != bottom; i--){
                cout << arr[i] << " ";
            }    cout << endl;
        }

        bool menu(){
            int choice = 0;
            cout 
                << "Stack Operations [Array Implementation]\n"
                << "[1. push, " 
                << "2. pop, " 
                << "3. display, "
                << "4. exit]\n"
                << "Enter choice : ";
            cin >> choice;
            switch(choice) {
                case 1: this->push();
                        break;
                case 2: this->pop();
                        break;
                case 3: this->display();
                        break;
                default: cout << "Exit? -> ";
                         return false;
            }   return true;
        }
};

int main(void){
    Stack<int> n1;
    bool cont = true;
    do {
        cont = n1.menu();
    } while (cont);
    return 0;
}

/* OUTPUT
   Enter size : 5
   [STACK INIT]
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   Enter element : 10
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   Enter element : 15
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 2
   Popped element -> 15
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   Enter element : 20
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   Enter element : 30
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   Enter element : 40
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   Enter element : 50
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 1
   STACK OVERFLOW DETECTED!
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 3
   Stack elements [5/5] : 50 40 30 20 10
   Stack Operations [Array Implementation]
   [1. push, 2. pop, 3. display, 4. exit]
   Enter choice : 4
   Exit? -> [STACK DESTROYED]
   */
