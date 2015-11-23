// Stacks using Nodes
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* below;
};

// Pop from end, Push to end
class Stack {
    Node *top;

public:
    Stack() {
        top = NULL;
    }
    int pop() {
        Node* temp = top;
        top = top->below;
        return temp->data;
    }

    int peek() {
        return top->data;
    }

    void push(int d) {
        Node* node = new Node();
        node->data = d;
        node->below = top;
        top = node;
    }
};

int main() {
    Stack S;
    S.push(5);
    S.push(2);
    cout<<S.pop()<<endl;
    S.push(10);
    cout<<S.pop();
}
