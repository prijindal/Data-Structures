#include <iostream>
using namespace std;

// sequentialSearch(5,[1,2,3],3)
bool sequentialSearch(int data,int arr[], int l) {
    int i = 0;
    while(i < l) {
        if(data == arr[i]) {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int A[] = {1,2,4,5,6,7};
    cout<<sequentialSearch(4,A,6);
}
