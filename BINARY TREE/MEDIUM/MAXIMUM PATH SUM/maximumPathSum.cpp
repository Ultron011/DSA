/**
 * Problem -  Finds the maximum path sum in a binary tree.
 * 
 * The path can start and end at any node in the tree. The path must contain at least one node and does not need to go through the root.
 * 
 * Statement : Given a binary tree, find the maximum path sum. The path can start and end at any node in the tree.
 * 
 * Sample Input :
 *     Input: root = [1, 2, 3]
 * 
 * Sample Output :
 *     Output: 6
 * 
 * Explanation :
 *     The maximum path sum is obtained by the path 2 -> 1 -> 3, which gives a sum of 6.
 * 
 * Sample Input :
 *     Input: root = [-10, 9, 20, null, null, 15, 7]
 * 
 * Sample Output :
 *     Output: 42
 * 
 * Explanation :
 *     The maximum path sum is obtained by the path 15 -> 20 -> 7, which gives a sum of 42.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(N^2) where N is the number of nodes in the Binary Tree.
        
    Space Complexity -
        O(H) where H is the height of the Binary Tree.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
  
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        int maxPathDown(Node* root,int& maxi) {
            if (!root) return 0;

            int leftSum = max(0, maxPathDown(root->left, maxi));
            int rightSum = max(0, maxPathDown(root->right, maxi));

            maxi = max(maxi, leftSum + rightSum + root->data);
            return root->data + max(leftSum, rightSum);
        }

        int maxPathSum(Node* root) {
            int maxi = INT_MIN;
            maxPathDown(root, maxi);
            return maxi;
        }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;

    int maxPathSum = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;


    return 0;
}
   