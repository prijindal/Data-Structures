#include <iostream>
#define MAX 100
using namespace std;

class Queue {
    int arr[MAX];
    int count;
public:
    Queue() {
        count = 0;
    }

    // Save in Front
    void enqueue(int data) {
        int i;
        for(i = count-1;i >= 0;--i) {
            arr[i+1] = arr[i];
        }
        arr[0] = data;
        count++;
    }


    int dequeue() {
        return arr[--count];
    }
};


int main() {
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(4);
    Q.enqueue(2);
    cout<<Q.dequeue();
}
