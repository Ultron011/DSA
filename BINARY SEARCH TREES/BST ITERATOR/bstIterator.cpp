#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(1)

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
    stack<TreeNode*> myStackDesc;
    
    void pushAll(TreeNode* node) {
        while (node) {
            myStack.push(node);
            node = node->left;
        }
    }

    void pushAllRight(TreeNode* node) {
        while (node) {
            myStackDesc.push(node);
            node = node->right;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
        pushAllRight(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next () {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    int before() {
        if (myStack.empty()) return -1;
        TreeNode* tmpNode = myStackDesc.top();
        myStackDesc.pop();
        pushAllRight(tmpNode->left);
        return tmpNode->val;
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
    
  
    
    BSTIterator* it = new BSTIterator(root);
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->before() << endl;
    cout << it->before() << endl;



    return 0;
}
  