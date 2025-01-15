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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && (root->val < prev->val)) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

    public:
        void recoverTree(TreeNode* root) {
            first = middle = last = NULL;
            prev = new TreeNode(INT_MIN);
            inorder(root);
            if (first && last) swap(first->val , last->val);
            else if (first && middle) swap(first->val, middle->val);
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
    root->left->left = new TreeNode(9);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree before recovery : "<< endl;
    printInOrder(root);
    cout << endl;
    
    Solution solution;
    solution.recoverTree(root);

    cout << "Binary Search Tree after recovery : "<< endl;
    printInOrder(root);
    cout << endl;



    return 0;
}
  