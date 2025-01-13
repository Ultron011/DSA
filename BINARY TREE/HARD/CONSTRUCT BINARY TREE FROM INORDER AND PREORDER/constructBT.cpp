/**
 * Problem : Construct Binary Tree from Inorder and Preorder Traversal
 * 
 * Description : Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree 
 * and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * Explanation : The binary tree is constructed as follows:
 * 
 *     3
 *    / \
 *   9  20
 *      / \
 *     15  7
 * 
 * The preorder traversal of the constructed binary tree is [3,9,20,15,7] and the inorder traversal is [9,3,15,20,7].
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: 
        O(N) where n is the number of nodes.

    Space complexity: 
        O(N), where n is the number of nodes.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart+1, preStart + numsLeft, inorder, inStart, inRoot -1, inMap);
        root->right = buildTree(preorder, preStart+ numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
    
};


void printInorder(TreeNode* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printVector(vector<int>&vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    
    cout << "Inorder Vector: ";
    printVector(inorder);
    
    cout << "Preorder Vector: ";
    printVector(preorder);
    
    Solution sol;

    TreeNode* root = sol.buildTree(preorder, inorder);
    
    cout << "Inorder of Unique Binary Tree Created: "<< endl;
    printInorder(root);
    cout << endl;


    return 0;
}