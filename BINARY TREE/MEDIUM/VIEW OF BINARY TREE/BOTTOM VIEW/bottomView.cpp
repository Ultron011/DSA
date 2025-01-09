/**
 * Problem: Bottom View of a Binary Tree
 * 
 * Given a binary tree, print the bottom view of the binary tree. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.
 * 
 * The bottom view contains the last node at each horizontal distance from the root. If there are multiple nodes at the same horizontal distance, the bottom-most node is considered.
 * 
 * Sample Input:
 *         20
 *        /  \
 *      8     22
 *     / \   /  \
 *    5   3 4    25
 *       / \
 *      10  14
 * 
 * Sample Output:
 * 5 10 3 14 25
 * 
 * Explanation:
 * The nodes at the bottom view are:
 * - Horizontal distance -2: Node 5
 * - Horizontal distance -1: Node 10
 * - Horizontal distance 0: Node 3
 * - Horizontal distance 1: Node 14
 * - Horizontal distance 2: Node 25
 * 
 * Therefore, the bottom view of the given binary tree is 5, 10, 3, 14, 25.
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

class Solution{
public:
    
    vector<int> bottomView(Node* root){
        if (!root) return {};
        vector<int> ans;
        map<int, int> mpp;
        queue<pair<Node* , int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            mpp[line] = node->data;

            if (node->left) q.push({node->left, line-1});
            if (node->right) q.push({node->right, line+1});
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<int> bottomView =
                    solution.bottomView(root);

    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomView){
        cout << node << " ";
    }

    return 0;
}