// Queue using Nodes
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Dequeue and enqueue
class Queue {
    Node* front;
    Node *rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data) {
        Node* node = new Node;
        node->data = data;
        node->next = NULL;
        if(front == NULL) {
            front = rear = node;
            rear->next = NULL;
        }
        else {
            rear->next = node;
            rear = node;
            rear->next = NULL;
        }
    }

    int dequeue() {
        Node *temp = front;
        int data = temp->data;
        front = front->next;
        delete temp;
        return data;
    }
};

int main() {
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(4);
    Q.enqueue(2);
    cout<<Q.dequeue();
}
