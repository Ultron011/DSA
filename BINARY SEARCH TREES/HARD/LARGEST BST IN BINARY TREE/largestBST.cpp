#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N)

    Space complexity -
        O(1)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class NodeValue {
    public:
        int maxNode, minNode, maxSize;

        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};

class Solution {
    NodeValue largestBSTHelper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    public:
        int largestBST(TreeNode* root) {
            return largestBSTHelper(root).maxSize;
        }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    
    cout << "Binary Tree : "<< endl;
    printInOrder(root);
    cout << endl;
    
    Solution solution;
    int res = solution.largestBST(root);

    cout << "Largest Binary Search Tree : " << res << endl;



    return 0;
}
  