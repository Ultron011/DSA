/**
 * Function to perform postorder traversal of a binary tree.
 *
 * Problem Statement:
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 * Postorder traversal is a type of depth-first traversal where the nodes are iteratively visited in the order: left subtree, right subtree, root node.
 *
 * Input:
 * - TreeNode* root: A pointer to the root node of the binary tree.
 *
 * Output:
 * - vector<int>: A vector containing the values of the nodes in postorder traversal order.
 *
 * Time Complexity:
 * - O(n): Where 'n' is the number of nodes in the binary tree. Each node is visited exactly once.
 *
 * Space Complexity:
 * - O(n): Where 'n' is the number of nodes in the binary tree.
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


vector<int> postOrder(Node* root) {
    if (!root) return {};
    vector<int> arr;

    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left) st1.push(root->left);
        if (root->right) st1.push(root->right);
    }

    while (!st2.empty()) {
        arr.push_back(st2.top()->data);
        st2.pop();
    }

    return arr;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    cout << "Postorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
