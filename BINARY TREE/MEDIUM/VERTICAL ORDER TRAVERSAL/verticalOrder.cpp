/**
 * Problem - Vertical Order Traversal of Binary Tree
 * 
 * This function performs a vertical order traversal of a binary tree.
 * In vertical order traversal, nodes are visited column by column from left to right.
 * Nodes in the same column are visited from top to bottom.
 * 
 * Statement : Given the root of a binary tree, return the vertical order traversal of its nodes' values.
 * 
 * Input :
 *     Input: root = [3,9,20,null,null,15,7]
 * 
 * Output :
 *     Output: [[9],[3,15],[20],[7]]
 * 
 * Explanation :
 *     The binary tree is:
 *         3
 *        / \
 *       9  20
 *          / \
 *         15  7
 * 
 *     The vertical order traversal is:
 *     - Column -1: [9]
 *     - Column  0: [3, 15]
 *     - Column  1: [20]
 *     - Column  2: [7]
 * 
 *     Therefore, the output is [[9],[3,15],[20],[7]].
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(N * log(N)) where N represents the number of nodes in the Binary Tree.    

    Space Complexity -
        O(N) where H is the number of nodes in the Binary Tree.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
 
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    vector<vector<int>> findVertical(Node* root){
        
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<Node*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            Node* temp = p.first;

            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(temp->data);

            if (temp->left) {
                todo.push({temp->left, { x- 1, y + 1}});
            }
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<vector<int>> verticalTraversal =
                    solution.findVertical(root);

    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);

    return 0;
}