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

class Solution {
    long prev = INT_MIN;
private:
    void inorder(TreeNode* root, bool& flag) {
        if (!root) return;

        inorder(root->left, flag);
        if (prev < root->val) {
            prev = root->val;
        } else {
            flag = false;
            return;
        }
        inorder(root->right, flag);
    }

public:

    bool isValidBST(TreeNode* root) {
        bool flag = true;
        inorder(root, flag);
        return flag;
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
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;
    
  
    
    Solution solution;

    if (solution.isValidBST(root)) {
        cout << "It is a valid binary tree" << endl;
    } else {
        cout << "It is an invalid binary tree" << endl;
    }

    return 0;
}
  