#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(log(N)) ,  where N is the number of nodes in the binary search tree.

    Space complexity -
        O(1) , where H is the height of the binary search tree.
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

    TreeNode* cur = root;
    while (true) {
        if (cur->val <= val) {
            if (cur->right) cur = cur->right;
            else {
                cur->right = new TreeNode(val);
                break;
            }
        } else {
            if (cur->left) cur = cur->left;
            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }

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