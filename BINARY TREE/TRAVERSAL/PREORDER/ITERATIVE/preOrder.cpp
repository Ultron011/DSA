/**
 * Problem: Preorder Traversal of a Binary Tree
 * 
 * Problem Statement:
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 * Preorder traversal is a type of depth-first traversal where the nodes are recursively visited in this order:
 * 1. Visit the root node.
 * 2. Traverse the left subtree.
 * 3. Traverse the right subtree.
 * 
 * Input:
 * - TreeNode* root: A pointer to the root node of the binary tree.
 * 
 * Output:
 * - vector<int>: A vector containing the values of the nodes visited in preorder traversal order.
 */

/**
 * Time Complexity:
 * The time complexity of the iterative approach is O(n), where n is the number of nodes in the binary tree.
 * 
 * Space Complexity:
 * The space complexity of the iterative approach is O(n) in case of skewed tree and O(log(n)) in case of balanced binary tree.
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


vector<int> preOrder(Node* root){
   
    vector<int> preorder;
    if (!root) return preorder;

    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);

        if (root->right) st.push(root->right);
        if (root->left) st.push(root->left);
    }

    return preorder;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = preOrder(root);

    cout << "Preorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
