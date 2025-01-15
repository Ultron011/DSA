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

    TreeNode* build(vector<int> &preorder, int &i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }

public:

    TreeNode* bstFromPreorder(vector<int> &preorder) {
        int i = 0;
        return build(preorder, i , INT_MAX);
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
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    Solution solution;
    TreeNode* root = solution.bstFromPreorder(preorder);

    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    return 0;
}
  