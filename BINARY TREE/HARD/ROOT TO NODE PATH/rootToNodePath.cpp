/**
 * Problem : Finds the path from the root to a given node in a binary tree.
 *
 * This function searches for a specified node in a binary tree and returns the path from the root to that node.
 * If the node is found, the path is returned as a vector of integers representing the node values along the path.
 * If the node is not found, an empty vector is returned.
 * 
 * Input:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 * Target: 5
 *
 * Output: [1, 2, 5]
 *
 * Explanation:
 * The path from the root (1) to the target node (5) is 1 -> 2 -> 5.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: 
        O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once in the inorder traversal.

    Space complexity: 
        O(N) where N is the number of nodes in the binary tree. The space complexity is O(N) because the maximum size of the stack is N.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:

    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        if (!root) return false;

        arr.push_back(root->val);

        if (root->val == x) return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }

        arr.pop_back();
        return false;
    }

    
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        if (A == nullptr) return arr;
        getPath(A, arr, B);
        return arr;
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

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " <<
        targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}