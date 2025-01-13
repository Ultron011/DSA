/**
 * Problem : Perform Morris Inorder Traversal of a Binary Tree.
 *
 * This function implements the Morris Inorder Traversal algorithm to traverse a binary tree
 * without using recursion or a stack. The algorithm uses threaded binary trees to achieve
 * O(1) space complexity.
 *
 * Problem Statement:
 * Given the root of a binary tree, return its inorder traversal using the Morris Traversal technique.
 *
 * Sample Input:
 *     1
 *      \
 *       2
 *      /
 *     3
 *
 * Sample Output:
 * [1, 3, 2]
 *
 * Explanation:
 * The inorder traversal of the given binary tree is as follows:
 * 1. Start at the root node (1).
 * 2. Since 1 has no left child, visit 1.
 * 3. Move to the right child of 1, which is 2.
 * 4. 2 has a left child (3), so find the inorder predecessor of 2, which is 3.
 * 5. Make 2 the right child of 3 (threading the tree).
 * 6. Move to the left child of 2, which is 3.
 * 7. Since 3 has no left child, visit 3.
 * 8. Move to the right child of 3, which is 2 (due to threading).
 * 9. Visit 2 and remove the thread.
 * 10. The traversal is complete, resulting in the output [1, 3, 2].
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
    
    vector<int> getInorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }  

                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
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
    
    vector<int> inorder = sol.getInorder(root);

    cout << "Binary Tree Morris Inorder Traveral: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}