#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class List {
    Node* head;
public:
    List() {
        head = NULL;
    }

    void del(int index) {
        // Delete the ith element
    }

    void append(int item) {
        // Append at the end
        Node* node = new Node;
        node->data = item;
        if(head == NULL) {
            node->prev = NULL;
            node->next = NULL;
            head = node;
            return ;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        node->prev = temp;
        node->next = NULL;
        temp->next = node;
    }

    void insert(int item, int index) {
        // Insert at ith pos
        Node* node = new Node;
        node->data = item;
        if(head == NULL) {
            node->prev = NULL;
            node->next = NULL;
            head = node;
            return ;
        }
        Node* temp = head;
        int i = 0;
        while(temp->next != NULL && i < index) {
            temp = temp->next;
            i++;
        }
        node->prev = temp;
        node->next = NULL;
        temp->next = node;
    }

    int pop() {
        // Pop last element
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        int data = temp->data;
        Node* prev = temp->prev;
        prev->next = NULL;
        return data;
    }

    int pop(int index) {
        // Pop ith element
        int i = 0;
        Node* temp = head;
        while(temp->next != NULL && i < index) {
            temp = temp->next;
            i++;
        }
        int data = temp->data;
        Node* prev = temp->prev;
        prev->next = NULL;
        return data;
    }
};

int main() {
    List L;
    L.append(10);
    L.append(15);
    L.append(20);
    cout<<L.pop()<<'\n';
    cout<<L.pop()<<'\n';
}
