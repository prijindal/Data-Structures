#include <iostream>
using namespace std;

// binarySearch(5,[1,2,3],3)
bool binarySearch(int data, int arr[], int l) {
    int i = 0;
    int start = 0;
    int last = l - 1;
    int mid;
    while(last > start) {
        mid = (start+last)/2;
        if(arr[mid] > data) {
            last = mid;
        }
        else if(arr[mid] < data) {
            start = mid+1;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    int A[] = {1,2,4,5,6,7};
    cout<<binarySearch(1,A,6)<<endl;
    cout<<binarySearch(2,A,6)<<endl;
    cout<<binarySearch(3,A,6)<<endl;
    cout<<binarySearch(4,A,6)<<endl;
}
