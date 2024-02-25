#include <iostream>
#include <stdexcept>
template <typename T, int MAX_SIZE>
class CircularQueue {
private:
    T arr[MAX_SIZE];
    int front;
    int rear;
    int itemCount;
public:
    CircularQueue() : front(0), rear(-1), itemCount(0) {}
    void enqueue(T val) {
        if (isFull()) {
            throw std::overflow_error("Queue Overflow! Cannot enqueue into a full queue.");
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
        ++itemCount;
    }
    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue Underflow! Cannot dequeue from an empty queue.");
        }
        front = (front + 1) % MAX_SIZE;
        --itemCount;
    }
    T peek() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty! No front element to peek.");
        }
        return arr[front];
    }
    bool isEmpty() {
        return itemCount == 0;
    }
    bool isFull() {
        return itemCount == MAX_SIZE;
    }
};
int main() {
    const int MAX_SIZE = 5;
    CircularQueue<int, MAX_SIZE> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Front element of the queue: " << queue.peek() << std::endl;
    queue.dequeue();
    std::cout << "Front element of the queue after dequeue: " << queue.peek() << std::endl;
    queue.dequeue();
    std::cout << "Front element of the queue after dequeue: " << queue.peek() << std::endl;
    std::cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
