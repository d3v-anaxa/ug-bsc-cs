#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
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
            head = temp->next;
            delete temp;
            return;
        }
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) return;
        prev->next = temp->next;
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
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void concatenate(LinkedList<T>& otherList) {
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = otherList.head;
    }
    LinkedList<T> operator+(LinkedList<T>& otherList) {
        LinkedList<T> newList = *this;
        newList.concatenate(otherList);
        return newList;
    }
    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    LinkedList<int> list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    LinkedList<int> list2;
    list2.insert(4);
    list2.insert(5);
    std::cout << "List 1: ";
    list1.display();
    std::cout << "List 2: ";
    list2.display();
    list1.insert(4);
    list1.display();
    list1.deleteNode(3);
    list1.display();
    std::cout << "Is 2 present in list 1? " << (list1.search(2) ? "Yes" : "No") << std::endl;
    list1.reverse();
    std::cout << "Reversed List 1: ";
    list1.display();
    LinkedList<int> concatenatedList = list1 + list2;
    std::cout << "Concatenated List: ";
    concatenatedList.display();
    return 0;
}
