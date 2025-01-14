#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(log(N)) ,  where N is the number of nodes in the binary search tree.

    Space complexity -
        O(1)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) : val(d), left(NULL), right(NULL) {};
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);

    return root;
}

void printInOrder(TreeNode* root) {
    if (!root) return;

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);

}

int main() {

    TreeNode* root = NULL;
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 12);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 21);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 16);

    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;


  return 0;
}