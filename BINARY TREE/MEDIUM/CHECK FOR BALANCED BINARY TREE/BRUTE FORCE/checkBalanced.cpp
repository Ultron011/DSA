/**
 * This function checks if a given binary tree is balanced. 
 * A binary tree is considered balanced if the height of the two subtrees of any node never differ by more than one.
 *
 * Problem Statement:
 * Given the root of a binary tree, determine if it is height-balanced.
 *
 * Sample Input:
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 *
 * Sample Output:
 * true
 *
 * Explanation:
 * The given binary tree is balanced because the height difference between the left and right subtrees of every node is not more than one.
 *
 * Sample Input:
 *     1
 *    / 
 *   2   
 *  / 
 * 3   
 *
 * Sample Output:
 * false
 *
 * Explanation:
 * The given binary tree is not balanced because the height difference between the left and right subtrees of the root node is more than one.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(N^2) where N is the number of nodes in the Binary Tree.
        
    Space Complexity -
        O(H) where H is the height of the Binary Tree.
*/

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node* node) {
    if (!node) return 0;

    int lh = height(node->left);
    int rh = height(node->right);

    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    if (!root) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1) return false;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    if (!left || !right) return false;

    return true;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Checking if the tree is balanced
    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}