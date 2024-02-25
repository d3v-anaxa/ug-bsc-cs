#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() : top(nullptr) {}
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop from an empty stack." << std::endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    T peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty! No top element to peek." << std::endl;
            return T();
        }
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};
int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Top element of the stack: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top element of the stack after popping: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top element of the stack after popping: " << stack.peek() << std::endl;
    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
