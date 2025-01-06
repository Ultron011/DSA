/**
 * Function to perform level order traversal of a binary tree.
 *
 * This function traverses the binary tree level by level, starting from the root,
 * and processes all nodes at each level before moving to the next level.
 *
 * Input:
 * - TreeNode* root: A pointer to the root node of the binary tree.
 *
 * Output:
 * - vector<vector<int>>: A 2D vector where each sub-vector contains the values of the nodes
 *   at each level of the binary tree, from top to bottom.
 *
 * Time Complexity:
 * - O(n): Where 'n' is the number of nodes in the binary tree. Each node is visited once.
 *
 * Space Complexity:
 * - O(w): Where 'w' is the number of nodes in the binary tree. 
 *         The maximum width of the tree (number of nodes in the largest level) determines the maximum size of the queue.
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder1(Node* root) {
    if (!root) return {};

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    vector<vector<int>> ans;
    vector<int> currLevel;

    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if (currNode == nullptr) {
            ans.push_back(currLevel);
            currLevel.clear();
            if (q.empty()) break;
            q.push(nullptr);
        } else {
            currLevel.push_back(currNode->data);

            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }
    }

    return ans;
}

vector<vector<int>> levelOrder2(Node* root) {
    if (!root) return {};

    queue<Node*> q;
    q.push(root);

    vector<vector<int>> ans;
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        ans.push_back(level);
    }
    return ans;   
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = levelOrder2(root);

    cout << "Inorder Traversal: \n";
    for(auto it : result) {
        for (int val : it) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << endl;


    return 0;
}