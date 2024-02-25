#include <iostream>
#include <stdexcept>
template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};
template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    Deque() : front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }
    void insertFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
    void insertRear(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }
    void deleteFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque Underflow! Cannot delete from an empty deque.");
        }
        Node<T>* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }
    void deleteRear() {
        if (isEmpty()) {
            throw std::underflow_error("Deque Underflow! Cannot delete from an empty deque.");
        }
        Node<T>* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }
    void display() {
        Node<T>* temp = front;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    Deque<int> deque;
    deque.insertFront(1);
    deque.insertFront(2);
    deque.insertRear(3);
    deque.insertRear(4);
    std::cout << "Deque elements (front to rear): ";
    deque.display();
    deque.deleteFront();
    deque.deleteRear();
    std::cout << "Deque elements after deletion (front to rear): ";
    deque.display();
    return 0;
}
