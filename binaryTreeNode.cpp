#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Binary Search Tree
class Tree {
    Node* root;
public:
    Tree() {
        root = NULL;
    }

    void add(int item) {
        insert(root, item);
    }

    void remove(int item) {
        removeHelper(root, item);
    }

    bool search(int item) {
        return searchHelper(root, item);
    }

    void inOrderTraversal() {
        inOrder(root);
    }
private:
    void removeHelper(Node*& root, int data) {
        if(root == NULL) {
            return;
        }
        if(data > root->data) {
            removeHelper(root->right, data);
        }
        else if(data < root->data) {
            removeHelper(root->left, data);
        }
        else {
            DeleteNode(root);
        }
    }

    void DeleteNode (Node *&tree) {
        Node *temp = tree;
        if(tree->left!=NULL && tree->right!=NULL) {
            temp = tree->left;
            // find right most node
            while(temp->right != NULL) {
                temp = temp->right;
            }
            tree->data = temp->data;
            removeHelper(tree->left, temp->data);
        }
        else if(tree->left==NULL && tree->right!=NULL) {
            // Node with right child
            tree = tree->right;
            delete temp;
        }
        else if(tree->left!=NULL && tree->right==NULL) {
            // Node with left child
            tree = tree->left;
            delete temp;
        }
        else {
            // Node without any child
            tree = NULL;
            delete temp;
        }
    }

    bool searchHelper(Node*& root, int data) {
        if(root == NULL) return false;
        if(root->data == data) {
            return true;
        }
        else if(data > root->data) {
            return searchHelper(root->right, data);
        }
        else {
            return searchHelper(root->left, data);
        }
    }

    void insert(Node*& root, int data) {
        if(root == NULL) {
            Node* node = new Node;
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            root = node;
        }
        else if(data > root->data) {
            insert(root->right, data);
        }
        else if(data < root->data) {
            insert(root->left, data);
        }
    }

    void inOrder(Node*& node) {
        if(node == NULL) return ;
        inOrder(node->left);
        cout<<node->data<<'\n';
        inOrder(node->right);
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
    // T.remove(7);
    T.remove(19);
    // T.remove(45);
    // T.remove(66);
    T.inOrderTraversal();
    // cout<<T.search(19);
}
