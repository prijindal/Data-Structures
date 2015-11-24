#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
    Node* head;
public:
    List() {
        head = NULL;
    }

    void append(int data) {
        Node* node = new Node;
        node->data = data;
        if(head == NULL) {
            head = node;
            head->next = head;
            return;
        }
        Node* temp = head;
        do {
            cout<<"In Append "<<temp->data<<'\n';
            temp = temp->next;
        } while (temp->next != head);
        node->next = head;
        temp->next = node;
    }

    int pop() {
        Node *prev = head;
        Node* temp = head->next;
        do {
            prev = prev->next;
            temp = temp->next;
        } while (temp->next != head);
        int data = temp->data;
        prev->next = head;
        delete temp;
        return data;
    }
};

int main() {
    List L;
    L.append(10);
    L.append(13);
    cout<<L.pop()<<'\n';
    cout<<L.pop()<<'\n';
}
