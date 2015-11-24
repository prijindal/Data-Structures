#include <iostream>
#define SIZE 11
using namespace std;

class Hash {
    int arr[SIZE];
    int count;
public:
    Hash() {
        count = 0;
        for(int i = 0;i < SIZE;++i) {
            arr[i] = NULL;
        }
    }

    void put(int data) {
        int pos = hashfunction(data);
        if(arr[pos] == NULL) {
            arr[pos] = data;
        }
        else {
            int i = 0;
            int newhash = rehash(pos, i);
            while(arr[newhash] != NULL && newhash!= pos) {
                newhash = rehash(pos, ++i);
            }
            arr[newhash] = data;
        }
    }

    int get(int item) {
        int hashed = hashfunction(item);
        if (arr[hashed] == item){
            return true;
        }
        else{
            int increment = 1;
            int newhash = rehash(hashed, increment);
            while (newhash!=hashed) {
                if (arr[newhash] == item){
                    return true;
                }
                increment+=1;
                newhash = rehash(newhash, increment);
            }
            return false;
        }
    }

private:
    int hashfunction(int key) {
        return key%SIZE;
    }

    int rehash(int oldhash, int i) {
        return (oldhash + i*i)%SIZE;
    }
};

int main() {
    Hash H;
    H.put(12);
    H.put(24);
    cout<<H.get(12);
}
