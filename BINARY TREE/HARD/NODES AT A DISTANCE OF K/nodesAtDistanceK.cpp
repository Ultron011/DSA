/**
 * Problem : Nodes at a Distance K in a Binary Tree
 * 
 * Description : Given a binary tree, a target node, and an integer value K, 
 *              return all the nodes that are at distance K from the target node.
 *
 * Input :
 *        3
 *       / \
 *      5   1
 *     / \ / \
 *    6  2 0  8
 *      / \
 *     7   4
 * 
 * Target: 5, K: 2
 * 
 * Output :
 * [7, 4, 1]
 * 
 * Explanation : The nodes that are at distance 2 from the target node 5 are 7, 4, and 1.
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

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()) {
            int size = q.size();
            if (curr_level++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent_track[curr] && !visited[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }

        return result;
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

    int k = 2;

    Solution sol;
    vector<int> res = sol.distanceK(root, root->left, k);

    cout << "Nodes at distance " << k << " from the target are : " ;
    for (auto it : res) {
        cout << it << " ";
    }



    return 0;
}