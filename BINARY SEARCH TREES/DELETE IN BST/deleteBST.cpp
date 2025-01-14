#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(H) ,  where H is the height of the binary search tree.

    Space complexity -
        O(1) , where H is the height of the binary search tree.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) : val(d), left(NULL), right(NULL) {};
};

TreeNode* findLastRight(TreeNode* root) {
    if (!root->right) {
        return root;
    }
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root) {
    if (!root->left) {
        return root->right;
    } else if (!root->right) {
        return root->left;
    }

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;
    
    if (root->val == key) {
        return helper(root);
    }

    TreeNode* dummy = root;
    while (root) {
        if (root->val > key) {
            if (root->left && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } 
        else {
            if (root->right && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;

}

void printInOrder(TreeNode* root) {
    if (!root) return;

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);

}

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    int key = 8;
    root = deleteNode(root, key);

    cout << "Binary Tree after deleting " << key << " : " << endl;
    printInOrder(root);
    cout << endl;


  return 0;
}