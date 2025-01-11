/**
 * Problem: Lowest Common Ancestor in a Binary Tree
 * 
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q 
 * as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Example:
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 * 
 * Note:
 * - All the node values are unique.
 * - p and q are different and both values will exist in the binary tree.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: 
        O(N) where n is the number of nodes.

    Space complexity: 
        O(N), auxiliary space.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left) return right;
        else if (!right) return left;
        else return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution sol;

    TreeNode* lcs = sol.lowestCommonAncestor(root, root->left->left, root->left->right->right);

    cout << "Lowest Common Ancestor of is: " << lcs->val << endl;

    return 0;
}