#include <iostream>
using namespace std;

void selectionSort(int arr[], int l) {
    int i,j;
    for(i = l-1;i > 0;--i) {
        int pos = 0;
        for(j = 1;j < i+1 ;++j) {
            if(arr[j] > arr[pos]) {
                pos = j;
            }
        }
        // Swap pos & i
        int temp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = temp;
    }
}


void display(int arr[], int l) {
    int i;
    for (i = 0; i < l; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    int i;
    int A[] = {6,1,2,7,3,0};
    display(A, 6);
    selectionSort(A, 6);
    display(A, 6);

}
