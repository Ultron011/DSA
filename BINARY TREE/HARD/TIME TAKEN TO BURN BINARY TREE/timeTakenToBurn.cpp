/**
 * Problem : Time taken to burn a binary tree
 * 
 * Description : Given a binary tree and a leaf node from which a fire starts, 
 *              find the minimum time required to burn the entire binary tree. 
 *              The fire spreads to the adjacent nodes (parent and children) 
 *              in 1 unit of time.
 * 
 * Sample Input :
 *          1
 *         / \
 *        2   3
 *       / \
 *      4   5
 * 
 *        leaf = 5
 * 
 * Sample Output :
 *        4
 * 
 * Explanation :
 *        The fire starts at node 5 and spreads as follows:
 *        - Time 1: Node 5 burns.
 *        - Time 2: Node 2 burns.
 *        - Time 3: Node 1 and Node 4 burn.
 *        - Time 4: Node 3 burns.
 *        Therefore, the minimum time required to burn the entire binary tree is 4 units.
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

    int timeTaken(unordered_map<TreeNode*, TreeNode*> &mpp, TreeNode* target) {
        queue<TreeNode* > q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int time = 0;
        while (!q.empty()) {
            int size = q.size();

            /* If any of the child or parent node is burned or not */
            int fl = 0;
            
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                
                if (node->left && !visited[node->left]) {
                    fl = 1;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    fl = 1;
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (mpp[node] && !visited[mpp[node]]) {
                    fl = 1;
                    q.push(mpp[node]);
                    visited[mpp[node]] = true;
                }
            }

            // If any adjacent node burned, increase the time by 1
            if (fl) time++;
        }
        return time;
    }

    TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp, int target) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node->val == target) {
                res = node;
            }
            q.pop();
            if(node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

public:
    int minTimeToBurn(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        TreeNode* targetNode = bfsToMapParents(root, mpp, target);
        int time = timeTaken(mpp, targetNode);
        return time;
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

    int target = 5;

    Solution sol;
    int minTime = sol.minTimeToBurn(root, target);
    cout << "Minimum Time taken to burn the entire tree is : " << minTime << endl;

}