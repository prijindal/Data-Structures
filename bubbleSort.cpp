#include <iostream>
using namespace std;

void bubbleSort(int arr[], int l) {
    int i,j;
    for(i = 0;i < l;++i) {
        for(j = 0;j < l-i-1;++j) {
            if(arr[j+1] < arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
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
    bubbleSort(A, 6);
    display(A, 6);

}
