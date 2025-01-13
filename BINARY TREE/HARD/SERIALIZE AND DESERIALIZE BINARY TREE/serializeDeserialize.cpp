/**
 * Problem -  Serialize and Deserialize a Binary Tree
 *
 * Statement -
 * Given the root of a binary tree, implement two functions:
 * 1. `serialize(TreeNode* root) -> string`: Converts the binary tree into a single string.
 * 2. `deserialize(string data) -> TreeNode*`: Converts the string back into the binary tree.
 *
 * The serialized string should be such that it can be easily deserialized back into the original tree structure.
 *
 * Input :
 * Consider the following binary tree:
 * 
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 *
 * Output :
 * Serialized string: "1,2,null,null,3,4,null,null,5,null,null"
 * 
 * Explanation:
 * - The serialized string represents the tree in a pre-order traversal format.
 * - "1" is the root node.
 * - "2" is the left child of the root node.
 * - "null" indicates that the left child of node 2 is null.
 * - "null" indicates that the right child of node 2 is null.
 * - "3" is the right child of the root node.
 * - "4" is the left child of node 3.
 * - "null" indicates that the left child of node 4 is null.
 * - "null" indicates that the right child of node 4 is null.
 * - "5" is the right child of node 3.
 * - "null" indicates that the left child of node 5 is null.
 * - "null" indicates that the right child of node 5 is null.
 *
 * The deserialization function should be able to take this string and reconstruct the original binary tree.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N)

    Space complexity -
        O(N)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode * currNode = q.front();
            q.pop();

            if (!currNode) s.append("#,");
            else s.append(to_string(currNode->val)+',');

            if (currNode) {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                node->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};


void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}