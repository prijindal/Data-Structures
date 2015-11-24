#include <iostream>
using namespace std;

int partition(int arr[], int start, int last);
void quickSort(int arr[], int start, int last) {
    if(last > start) {
        int p = partition(arr, start, last);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, last);
    }
}

int partition(int arr[], int start, int last) {
    int pivot = arr[last];
    int i = start;
    int j;
    for(j = start;j < last; ++j) {
        if(pivot >= arr[j]) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[last];
    arr[last] = temp;
    return i;
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
    quickSort(A,0, 5);
    display(A, 6);
}
