/**
 * Problem Statement:
 * Given a binary tree, write a function to determine its height. The height of a binary tree 
 * is the number of edges on the longest path from the root node to a leaf node. A tree with 
 * only one node has a height of 0.
 *
 * Input:
 * - A binary tree represented by its root node.
 *
 * Output:
 * - An integer representing the height of the binary tree.
 *
 * Explanation:
 * The height of a binary tree is the length of the longest path from the root to a leaf. 
 * This can be determined by recursively finding the height of the left and right subtrees 
 * and taking the maximum of the two heights plus one (to account for the edge connecting 
 * the root to its subtrees).
 *
 * Example:
 * Consider the following binary tree:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 * The height of this tree is 2, as the longest path from the root to a leaf is 1 -> 2 -> 4 
 * or 1 -> 2 -> 5, which consists of 2 edges.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(N) where N is the number of nodes in the Binary Tree.
        
    Space Complexity -
        O(N) where N is the number of nodes in the Binary Tree.

*/

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxDepth(Node* root) {
    if (!root) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    int depth = maxDepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}