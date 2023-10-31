#include <iostream>
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
