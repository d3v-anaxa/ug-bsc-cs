#include <iostream>
#include <stdexcept>
template <typename T, int MAX_SIZE>
class Stack {
private:
    T arr[MAX_SIZE];
    int topIndex;
public:
    Stack() : topIndex(-1) {}
    void push(T val) {
        if (topIndex == MAX_SIZE - 1) {
            throw std::overflow_error("Stack Overflow! Cannot push onto a full stack.");
        }
        arr[++topIndex] = val;
    }
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow! Cannot pop from an empty stack.");
        }
        --topIndex;
    }
    T peek() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty! No top element to peek.");
        }
        return arr[topIndex];
    }
    bool isEmpty() {
        return topIndex == -1;
    }
};
int main() {
    const int MAX_SIZE = 5;
    Stack<int, MAX_SIZE> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "Top element of the stack: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top element of the stack after popping: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top element of the stack after popping: " << stack.peek() << std::endl;
    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
