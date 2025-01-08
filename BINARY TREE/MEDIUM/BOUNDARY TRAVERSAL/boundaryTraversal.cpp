/**
 * Problem - Boundary Order Traversal of a Binary Tree
 * 
 * This function performs a boundary order traversal of a binary tree. 
 * The boundary traversal of a binary tree involves traversing the boundary nodes of the tree in an anti-clockwise direction starting from the root.
 * The boundary includes the left boundary, leaves, and the right boundary (excluding the root and leaves already included).
 * 
 * The traversal order is:
 * 1. Left boundary nodes (excluding the leaf nodes and the root).
 * 2. All the leaf nodes.
 * 3. Right boundary nodes (excluding the leaf nodes and the root) in reverse order.
 * 
 * Input:
 *         1
 *       /   \
 *      2     3
 *     / \   / \
 *    4   5 6   7
 *       / \     \
 *      8   9     10
 * 
 * Output:
 * [1, 2, 4, 8, 9, 6, 10, 7, 3]
 * 
 * Explanation:
 * - The left boundary is [1, 2, 4].
 * - The leaf nodes are [4, 8, 9, 6, 10].
 * - The right boundary in reverse order is [10, 7, 3].
 * Combining these, we get [1, 2, 4, 8, 9, 6, 10, 7, 3].
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(N) where N is the number of nodes in the Binary Tree.
        
    Space Complexity -
        O(N) where H is the number of nodes in the Binary Tree.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
   
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {

    bool isLeaf(Node* root) {
        if (!root->left && !root->right) return true;
        return false;
    }

    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int> &res) {
        Node* curr = root->right;
        vector<int> tmp;
        while (curr) {
            if (!isLeaf(curr)) tmp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for (int i = tmp.size() - 1; i >= 0; i--) {
            res.push_back(tmp[i]);
        }
    }

    void addLeaves(Node* root, vector<int> &res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

public:
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }   
};

void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    vector<int> result = solution.printBoundary(root);

    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}