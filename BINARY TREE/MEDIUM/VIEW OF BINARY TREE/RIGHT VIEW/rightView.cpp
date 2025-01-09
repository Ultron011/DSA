/**
 * Problem: Right View of a Binary Tree
 * 
 * Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Sample Input:
 *     1
 *    / \
 *   2   3
 *    \   \
 *     5   4
 * 
 * Sample Output:
 * [1, 3, 4]
 * 
 * Explanation:
 * - From the right side, you can see the nodes with values 1, 3, and 4.
 * - Node 1 is the root and is visible.
 * - Node 3 is the right child of the root and is visible.
 * - Node 4 is the rightmost node at the last level and is visible.
 * - Node 2 and Node 5 are not visible from the right side.
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

        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);

    }
    
    vector<int> rightView(Node* root){
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

    vector<int> rightView =
                    solution.rightView(root);

    cout << "Right View Traversal: "<< endl;
    for(auto node: rightView){
        cout << node << " ";
    }

    return 0;
}