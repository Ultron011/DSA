/**
 * Function to perform Inorder traversal of a binary tree.
 *
 * Problem Statement:
 * Given the root of a binary tree, return the Inorder traversal of its nodes' values.
 * Inorder traversal is a type of depth-first traversal where the nodes are iteratively visited in the order: left subtree, root node, right subtree.
 *
 * Input:
 * - TreeNode* root: A pointer to the root node of the binary tree.
 *
 * Output:
 * - vector<int>: A vector containing the values of the nodes in Inorder traversal order.
 *
 * Time Complexity:
 * - O(n): Where 'n' is the number of nodes in the binary tree. Each node is visited exactly once.
 *
 * Space Complexity:
 * - O(h): Where 'h' is the height of the binary tree.
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



vector<int> inOrder(Node* root) {
    if (!root) return {};
    vector<int> arr;

    stack<Node*> st;
    Node* curr = root;
    while (true) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            if (st.empty()) break;
            curr = st.top();
            st.pop();
            arr.push_back(curr->data);
            curr = curr->right;
        }
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

    vector<int> result = inOrder(root);

    cout << "Inorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
