/**
 * Problem:  Zig Zag Traversal of Binary Tree
 *
 * This function performs a zig zag (or spiral) traversal of a binary tree.
 * In zig zag traversal, nodes are visited in a level order fashion but the
 * direction of traversal alternates between levels. For example, the first
 * level is traversed from left to right, the second level from right to left,
 * the third level from left to right, and so on.
 *
 * Input:
 *        1
 *       / \
 *      2   3
 *     / \ / \
 *    4  5 6  7
 *
 * Output: [1, 3, 2, 4, 5, 6, 7]
 *
 * Explanation:
 * Level 1: 1 (left to right)
 * Level 2: 3, 2 (right to left)
 * Level 3: 4, 5, 6, 7 (left to right)
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

class Solution {
public:
    
    vector<vector<int>> ZigZagLevelOrder(Node* root){
        if (!root) return {};
        vector<vector<int>> result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                int index = leftToRight ? i : (size - i - 1);
                level[index] = node->data;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            result.push_back(level);
        }
        return result;
    }
};



// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}