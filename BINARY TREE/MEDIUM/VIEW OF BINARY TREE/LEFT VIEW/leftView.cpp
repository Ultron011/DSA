/**
 * Problem: Left View of a Binary Tree
 * 
 * Given a binary tree, the task is to print the left view of the binary tree.
 * The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
 * 
 * Sample Input:
 *         1
 *       /   \
 *      2     3
 *     / \   / \
 *    4   5 6   7
 * 
 * Sample Output:
 * 1 2 4
 * 
 * Explanation:
 * The left view of the binary tree is 1, 2, 4. 
 * - 1 is the root and is visible from the left side.
 * - 2 is the left child of 1 and is visible from the left side.
 * - 4 is the left child of 2 and is visible from the left side.
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
    
    void recursion(Node* root, int level, vector<int> &res) {
        if (!root) return ;
        if (res.size() == level) res.push_back(root->data);

        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);

    }
    
    vector<int> leftView(Node* root){
        vector<int> res;
        recursion(root, 0, res);
        return res;
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

    vector<int> leftView =
                    solution.leftView(root);

    cout << "Left View Traversal: "<< endl;
    for(auto node: leftView){
        cout << node << " ";
    }

    return 0;
}