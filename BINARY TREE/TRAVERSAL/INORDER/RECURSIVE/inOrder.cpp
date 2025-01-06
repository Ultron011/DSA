/**
 * Function to perform Inorder traversal of a binary tree.
 *
 * Problem Statement:
 * Given the root of a binary tree, return the Inorder traversal of its nodes' values.
 * Inorder traversal is a type of depth-first traversal where the nodes are recursively visited in the order: left subtree, root node, right subtree.
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
 * - O(h): Where 'h' is the height of the binary tree. This space is used by the call stack during the recursion. In the worst case, the height of the tree could be 'n' (in case of a skewed tree), leading to O(n) space complexity. In the best case (balanced tree), the height would be log(n), leading to O(log(n)) space complexity.
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int> &arr) {
    if (!root) return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> inOrder(Node* root) {
    vector<int> arr;
    inorder(root, arr);
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
