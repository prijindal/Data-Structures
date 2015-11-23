#include <iostream>
using namespace std;

int insertionSort(int arr[], int l) {
    int i,j;
    for(i = 1;i < l;++i) {
        int cur = arr[i];
        j = i;
        while(j > 0 && arr[j-1] > cur) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = cur;
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
    insertionSort(A, 6);
    display(A, 6);

}
