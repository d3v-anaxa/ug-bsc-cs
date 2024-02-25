#include <iostream>
#include <stack>
#include <queue>
void reverseStack(std::stack<int>& original) {
    std::queue<int> tempQueue;
    while (!original.empty()) {
        tempQueue.push(original.top());
        original.pop();
    }
    while (!tempQueue.empty()) {
        original.push(tempQueue.front());
        tempQueue.pop();
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
    std::stack<int> tempStack = myStack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
    reverseStack(myStack);
    std::cout << "Reversed Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;
    return 0;
}
