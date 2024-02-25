#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
public:
    CircularLinkedList() : head(nullptr) {}
    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void deleteNode(T val) {
        if (!head) return;
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        if (temp->data == val) {
            Node<T>* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = temp->next;
            delete temp;
            return;
        }
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != val);
        if (temp == head) return;
        prev->next = temp->next;
        delete temp;
    }
    bool search(T val) {
        if (!head) return false;
        Node<T>* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    void reverse() {
        if (!head) return;
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        head->next = prev;
        head = prev;
    }
    void display() {
        if (!head) return;
        Node<T>* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};
int main() {
    CircularLinkedList<int> cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cll.insert(5);
    std::cout << "Original List: ";
    cll.display();
    std::cout << "Is 3 present in the list? " << (cll.search(3) ? "Yes" : "No") << std::endl;
    cll.deleteNode(3);
    std::cout << "List after deleting 3: ";
    cll.display();
    cll.reverse();
    std::cout << "Reversed List: ";
    cll.display();
    return 0;
}
