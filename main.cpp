#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        else {
            Node* temp = front;
            front = front->next;
            cout << "Removed item: " << temp->data << endl;
            delete temp;
            if (front == NULL) {
                rear = NULL;
            }
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        else {
            return front->data;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    int size() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Queue q;
    cout << "Is queue empty? " << q.isEmpty() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue size: " << q.size() << endl;
    cout << "Top element: " << q.top() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Queue size: " << q.size() << endl;
    cout << "Top element: " << q.top() << endl;

    return 0;
}
