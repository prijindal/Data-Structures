#include <iostream>
#define MAX 100
using namespace std;

class Tree {
    int arr[MAX];
public:
    // first: 0
    // this: i
    // left: 2*i + 1
    // right: 2*i + 2
    // parent: (i-1)/2
    Tree() {
        for(int i = 0;i < MAX;++i) {
            arr[i] = NULL;
        }
    }

    void add(int item) {
        insert(0, item);
    }

    void remove(int item) {
        removeHelper(0, item);
    }

    bool search(int item) {
        return searchHelper(0, item);
    }

    void inOrderTraversal() {
        inOrder(0);
    }

private:
    void insert(int root, int data) {
        if(arr[root] == NULL) {
            arr[root] = data;
        }
        else if(data > arr[root]) {
            insert(2*root+2, data);
        }
        else {
            insert(2*root+1, data);
        }
    }

    void inOrder(int root) {
        if(arr[root] == NULL) return ;
        inOrder(2*root+1);
        cout<<arr[root]<<'\n';
        inOrder(2*root+2);
    }

    bool searchHelper(int root, int item) {
        if(arr[root] == NULL) return false;
        if(item > arr[root]) {
            return searchHelper(2*root+2, item);
        }
        else if(item < arr[root]) {
            return searchHelper(2*root+1, item);
        }
        else {
            return true;
        }
    }

    void removeHelper(int root, int item) {
        if(arr[root] == NULL) {
            return ;
        }
        else if(item > arr[root]) {
            removeHelper(2*root+2, item);
        }
        else if(item < arr[root]) {
            removeHelper(2*root+1, item);
        }
        else {
            DeleteNode(root);
        }
    }

    void DeleteNode(int root) {
        int left = 2*root+1;
        int right = 2*root+2;
        if( left!=NULL && right != NULL) {
            int temp = 2*root+1;
            while(arr[2*temp+2]!=NULL) {
                temp = 2*temp+2;
            }
            arr[root] = arr[temp];
            arr[temp] = NULL;
        }
        else if( left==NULL && right != NULL) {
            arr[root] = arr[right];
            arr[right] = NULL;
        }
        else if( left!=NULL && right == NULL) {
            arr[root] = arr[left];
            arr[left] = NULL;
        }
        else {
            arr[root] = NULL;
        }
    }
};

int main() {
    Tree T;
    T.add(10);
    T.add(19);
    T.add(45);
    T.add(20);
    T.add(18);
    T.add(7);
    T.add(98);
    T.add(66);
    T.inOrderTraversal();
    T.remove(7);
    T.remove(19);
    // T.remove(45);
    // T.remove(66);
    T.inOrderTraversal();
    // cout<<T.search(19);
}
