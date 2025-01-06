#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) : data(d) , left(nullptr), right(nullptr) {}
};

void inOrderDFS(Node *root) {
    if (!root) return;

    inOrderDFS(root->left);
    cout << root->data << " ";
    inOrderDFS(root->right);
}


int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);

    cout << "In-order DFS: ";
    inOrderDFS(root);

    return 0;
}