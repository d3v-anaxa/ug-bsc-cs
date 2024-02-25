#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void deleteNode(T val) {
        if (!head) return;
        Node<T>* temp = head;
        if (temp->data == val) {
            head = temp->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;
        delete temp;
    }
    bool search(T val) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
    void reverse() {
        if (!head) return;
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
            tail = temp;
        }
    }
    void displayForward() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    void displayBackward() {
        Node<T>* temp = tail;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};
int main() {
    DoublyLinkedList<int> dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    std::cout << "Original List (Forward): ";
    dll.displayForward();
    std::cout << "Original List (Backward): ";
    dll.displayBackward();
    std::cout << "Is 2 present in the list? " << (dll.search(2) ? "Yes" : "No") << std::endl;
    dll.deleteNode(2);
    std::cout << "List after deleting 2: ";
    dll.displayForward();
    dll.reverse();
    std::cout << "Reversed List (Forward): ";
    dll.displayForward();
    std::cout << "Reversed List (Backward): ";
    dll.displayBackward();
    return 0;
}
