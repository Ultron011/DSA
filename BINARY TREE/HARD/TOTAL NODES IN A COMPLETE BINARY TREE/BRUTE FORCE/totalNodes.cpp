/**
 * Problem : Count Complete Tree Nodes
 *
 * This function counts the number of nodes in a complete binary tree.
 * A complete binary tree is a binary tree in which every level, except possibly the last, 
 * is completely filled, and all nodes are as far left as possible.
 *
 * Statement : Given the root of a complete binary tree, return the number of the nodes in the tree.
 *
 * Input :
 *     Input: root = [1,2,3,4,5,6]
 *     Explanation: The input represents the following complete binary tree:
 *            1
 *          /   \
 *         2     3
 *        / \   / 
 *       4   5 6
 * Output
 *     Output: 6
 *
 * Explanation : The complete binary tree has 6 nodes in total.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: 
        O(log(N)^2) where N is the number of nodes.

    Space complexity: 
        O(log(N)), where N is the number of nodes.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {

    int findHeightLeft(TreeNode* root) {
        int ht = 0;
        while (root) {
            ht++;
            root = root->left;
        }
        return ht;
    }

    int findHeightRight(TreeNode* root) {
        int ht = 0;
        while (root) {
            ht++;
            root = root->right;
        }
        return ht;
    }
    
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh) return (1<<lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    int totalNodes = sol.countNodes(root);

    cout << "Total number of nodes in the Complete Binary Tree: "
            << totalNodes << endl;



    return 0;
}