/**
 * Problem: Children Sum Property in a Binary Tree
 * 
 * Problem Statement:
 * Given a binary tree, write a function to check whether the tree satisfies the children sum property. 
 * In a binary tree, the children sum property is defined as:
 * For every node, the value of the node should be equal to the sum of the values of its left and right children.
 * Consider the value of NULL children as 0.
 * 
 * Sample Input:
 *         10
 *        /  \
 *       8    2
 *      / \  / \
 *     3  5 2  0
 * 
 * Sample Output:
 * True
 * 
 * Explanation:
 * - For the root node (10), the sum of its children (8 + 2) is 10.
 * - For the node with value 8, the sum of its children (3 + 5) is 8.
 * - For the node with value 2, the sum of its children (2 + 0) is 2.
 * - For the leaf nodes (3, 5, 2, 0), the children sum property is trivially satisfied as they have no children.
 * 
 * Since all nodes satisfy the children sum property, the output is True.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity - 
        O(N) where N is the number of nodes in the binary tree.

    Space Complexity -
        O(N) where N is the number of nodes in the Binary Tree.

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    void changeTree(TreeNode* root) {
        if (!root) return;
        int child = 0;
        if (root->left) child += root->left->val;
        if (root->right) child += root->right->val;

        if (child >= root->val) root->val = child;
        else {
            if (root->left) root->left->val = root->val;
            else if (root->right) root->right->val = root->val;
        }


        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if (root->left) tot += root->left->val;
        if (root->right) tot += root->right->val;
        if (root->left || root->right) root->val = tot;
    }
};


void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    sol.changeTree(root);

    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
  