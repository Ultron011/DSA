#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N)

    Space complexity -
        O(H)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse = true;
    
    void pushAll(TreeNode* node) {
        while (node) {
            myStack.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next () {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if (!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

};


class Solution {
    public:
        bool findTarget(TreeNode* root, int k) {
            if (!root) return false;
            BSTIterator l(root, false);
            BSTIterator r(root, true);

            int i = l.next();
            int j = r.next();
            while (i < j) {
                if (i + j == k) return true;
                else if (i + j < k) i = l.next();
                else j = r.next();
            }
            return false;
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
    int k = 16;

    bool isTwoSum = solution.findTarget(root, k);
    if (isTwoSum) cout << "True" << endl;
    else cout << "False" << endl;



    return 0;
}
  