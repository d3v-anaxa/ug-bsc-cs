#include <iostream>
#include <stack>
#include <queue>
void reverseStack(std::stack<int>& original) {
    std::queue<int> tempStack;
    while (!original.empty()) {
        tempStack.push(original.top());
        original.pop();
    }
    while (!tempStack.empty()) {
        original.push(tempStack.front());
        tempStack.pop();
    }
}
int main() {
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    std::cout << "Original Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    reverseStack(myStack);
    std::cout << "Reversed Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;
    return 0;
}
