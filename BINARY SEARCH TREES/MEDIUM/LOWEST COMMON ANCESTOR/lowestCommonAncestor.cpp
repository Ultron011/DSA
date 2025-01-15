#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(H)

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

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        int curr = root->val;
        if (curr < p->val && curr < q->val) return lowestCommonAncestor(root->right, p, q);
        if (curr > p->val && curr > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
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

    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right->right;

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    cout << "Lowest common ancestor of " << p->val << " and " << q->val << " is : " << lca->val << endl;

    return 0;
}
  