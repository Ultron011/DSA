/**
 * Problem: Symmetric Binary Tree or Not
 * 
 * Given a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 * 
 * A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.
 * 
 * Example:
 * 
 * Input:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * 
 * Output: true
 * 
 * Explanation: The given binary tree is symmetric.
 * 
 * Input:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * 
 * Output: false
 * 
 * Explanation: The given binary tree is not symmetric.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N) where N is the number of nodes in the Binary Tree.

    Space complexity -
        O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
   
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    private:
        bool isSymmetricHelp(Node* left, Node* right) {
            if (!left || !right) return left==right;

            if (left->data != right->data) return false;

            return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
        }

    public:
        bool isSymmetric(Node* root) {
            if (!root) return true;

            return isSymmetricHelp(root->left, root->right);
        }
};


void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;
    
    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);
    
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }

    return 0;
}