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
        O(N) where N is the number of nodes in the Binary Tree.
        
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

    int leftHeight = height(node->left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = height(node->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;
    
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {

    return height(root) != -1;
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