/**
 * Problem : Flattens a binary tree to a linked list in-place.
 *
 * The function takes the root of a binary tree and flattens it into a linked list in-place.
 * The linked list should use the right pointers to point to the next node in the list and 
 * the left pointers should be set to nullptr.
 *
 * Input:
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 *
 * Output:
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 *
 * Explanation:
 * The binary tree is flattened to a linked list where each node points to the next node in a pre-order traversal.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N) where N is the number of nodes in the Binary Tree. 

    Space complexity - 
        O(H) where H is the height of the Binary Tree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    void flatten(TreeNode* root) {
       if (!root) return;
       stack<TreeNode*> st;
       st.push(root);

       while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        if (curr->right) {
            st.push(curr->right);
        } 
        if (curr->left) {
            st.push(curr->left);
        }

        if (!st.empty()) {
            curr->right= st.top();
        }
        curr->left = NULL;
       }
    }
};


void printPreorder(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    sol.flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    

    return 0;
}