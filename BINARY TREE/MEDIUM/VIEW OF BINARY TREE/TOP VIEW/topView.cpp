/**
 * Problem: Top View of a Binary Tree
 * 
 * Given a binary tree, print the nodes in the top view of the binary tree. 
 * The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
 * 
 * Sample Input:
 *        1
 *       / \
 *      2   3
 *     / \   \
 *    4   5   6
 * 
 * Sample Output:
 * 4 2 1 3 6
 * 
 * Explanation:
 * When the tree is viewed from the top, the nodes 4, 2, 1, 3, and 6 are visible.
 * Node 5 is not visible because it is hidden behind node 2.
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
    
    vector<int> topView(Node* root){
        if (!root) return {};
        vector<int> ans;
        map<int, int> mpp;
        queue<pair<Node* , int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line= it.second;
            if (mpp.find(line) == mpp.end()) mpp[line] = node->data;

            if (node->left) q.push({node->left, line-1});
            if (node->right) q.push({node->right, line+1});
        }

        for (auto it: mpp) {
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

    vector<int> topView =
                    solution.topView(root);

    cout << "Top View Traversal: "<< endl;
    for(auto node: topView){
        cout << node << " ";
    }

    return 0;
}