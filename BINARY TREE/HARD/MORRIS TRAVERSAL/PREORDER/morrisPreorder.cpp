/**
 * Problem :  Perform Morris Preorder Traversal of a Binary Tree.
 *
 * This function implements the Morris Preorder Traversal algorithm, which is a way to traverse a binary tree without using any extra space for recursion or a stack. The algorithm modifies the tree during the traversal but restores it to its original state before exiting.
 *
 * Statement : Given the root of a binary tree, perform a preorder traversal using the Morris Traversal technique and return the list of visited nodes.
 *
 * Sample Input :
 *     Tree:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Sample Output :
 *     [1, 2, 4, 5, 3]
 *
 * Explanation :
 *     The preorder traversal visits nodes in the following order: root, left subtree, right subtree.
 *     For the given tree:
 *     - Start at root (1), visit it.
 *     - Move to left child (2), visit it.
 *     - Move to left child (4), visit it.
 *     - No left child, move to right child (5), visit it.
 *     - No children, backtrack to node (2), then to root (1).
 *     - Move to right child (3), visit it.
 *     - No children, traversal complete.
 */

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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    vector<int> getPreorder(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr) {
            if(curr->left == NULL) {
                preorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    
    vector<int> preorder = sol.getPreorder(root);

    cout << "Binary Tree Morris Preorder Traveral: ";
    for(int i = 0; i< preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}