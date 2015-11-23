#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int count;

public:
    Stack() {
        count = 0;
    }

    int pop() {
        return data = arr[--count];
    }

    int peek() {
        return arr[count-1];
    }

    void push(int data) {
        arr[count] = data;
        count++;
    }
};

int main() {
    Stack S;
    S.push(5);
    S.push(2);
    cout<<S.pop()<<endl;
    // S.push(10);
    cout<<S.pop();
}
