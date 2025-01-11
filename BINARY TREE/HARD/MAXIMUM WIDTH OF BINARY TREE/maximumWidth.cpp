/**
 * Problem : Maximum Width of a Binary Tree
 * 
 * Description : Given the root of a binary tree, return the maximum width of the given tree.
 *              The maximum width of a tree is the maximum width among all levels.
 *              The width of one level is defined as the length between the end-nodes 
 *              (the leftmost and rightmost non-null nodes), where the null nodes between 
 *              the end-nodes are also counted into the length calculation.
 * 
 * Input: 
 *        1
 *       / \
 *      3   2
 *     /     \  
 *    5       9 
 *   /         \
 *  6           7
 * 
 * Output: 8
 * 
 * Explanation: The maximum width exists in the fourth level with length 8 (6, null, null, null, null, null, null, 7).
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: 
        O(N) where n is the number of nodes.

    Space complexity: 
        O(N), where n is the number of nodes.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second;
            int first , last;

            for (int i = 0; i< size; i++) {
                int curr_ind = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = curr_ind;
                if (i == size - 1) last = curr_ind;
                if (node->left) q.push({node->left, 2*curr_ind + 1});
                if (node->right) q.push({node->right, 2*curr_ind + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};


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

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;

    return 0;
}