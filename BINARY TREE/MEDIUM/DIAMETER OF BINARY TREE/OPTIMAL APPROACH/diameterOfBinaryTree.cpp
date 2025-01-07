/**
 * Problem : Diameter of a Binary Tree
 * 
 * Description :
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * The length of a path between two nodes is represented by the number of edges between them.
 * 
 * Input: 
 *        1
 *       / \
 *      2   3
 *     / \     
 *    4   5    
 * 
 * Output: 3
 * 
 * Explanation:
 * The longest path is 4 -> 2 -> 1 -> 3 or 5 -> 2 -> 1 -> 3, and there are 3 edges in this path.
 * 
 * Note :
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - The value of each node is in the range [1, 100].
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

int height(Node* root, int &diameter) {
    if (!root) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter , lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node* root) {
    if (!root) return 0;
    int diameter = 0;

    height(root, diameter);
    return diameter;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);


    // Calculate the diameter of the binary tree
    int diameter = diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}