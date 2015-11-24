#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// append, pop,
class List {
    Node* head;
public:
    List() {
        head = NULL;
    }

    int del(int index) {
        // Delete index element and return it
        int i = 0;
        Node *prev = head;
        Node* temp = prev->next;
        while(temp->next!=NULL && i<index) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
    }

    int size() {
        // returns size of list
        int i = 0;
        Node* temp = head;
        while(temp!=NULL) {
            temp = temp->next;
            i++;
        }
        return i;
    }

    void append(int data) {
        // push in end
        Node *node = new Node;
        node->data = data;
        node->next = NULL;
        if(head == NULL) {
            head = node;
            return ;
        }
        Node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }

    int index(int item) {
        // returns index of item
        int i = 0;
        Node* temp = head;
        while(temp!=NULL && temp->data!=item) {
            temp = temp->next;
            i++;
        }
        return i;
    }

    void insert(int data, int index) {
        // Insert data at index
        int i = 0;
        Node* temp = head;
        while(temp!=NULL && i < index) {
            temp = temp->next;
            i++;
        }
        Node *node = new Node;
        node->data = data;
        node->next = temp->next;
        temp->next = node;
    }

    int pop() {
        // Pop last element
        int i = 0;
        Node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
            i++;
        }
        int data = temp->data;
        del(i);
        return data;
    }

    int pop(int index) {
        // Pop index element
        int i = 0;
        Node* temp = head;
        while(temp->next!=NULL && i < index) {
            temp = temp->next;
            i++;
        }
        int data = temp->data;
        del(i);
        return data;
    }
};

int main() {
    List L;
    L.append(11);
    L.append(13);
    L.append(14);
    L.insert(15,1);
    L.append(10);
    cout<<L.index(10);
    cout<<L.pop();
    cout<<L.pop();
}
