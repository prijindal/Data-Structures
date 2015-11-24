#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int last);
void mergeSort(int arr[], int start, int last) {
    if(last > start) {
        int mid = (start+last)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, start, mid, last);
    }
}

void merge(int arr[], int start, int mid, int last) {
    int i,j,nL,nR;
    nL = mid-start;
    nR = last-mid;
    int L[mid-start];
    int R[last-mid];
    for(i = start;i < mid;++i) {
        L[i-start] = arr[i];
    }
    for(j = mid;j < last;++j) {
        R[j-mid] = arr[j];
    }
    int k = start;
    i = j = 0;
    while(i < nL && j < nR) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < nL) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < nR) {
        arr[k] = R[j];
        j++;
        k++;
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
    mergeSort(A,0, 5);
    display(A, 6);
}
