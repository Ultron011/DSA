/**
 * Problem: Identical Trees or Not
 * 
 * Problem Statement:
 * Given the roots of two binary trees, determine if the trees are identical or not. 
 * Two binary trees are considered identical if they have the same structure and 
 * the nodes have the same values.
 * 
 * Sample Input:
 * Tree 1:       1
 *              / \
 *             2   3
 * 
 * Tree 2:       1
 *              / \
 *             2   3
 * 
 * Sample Output:
 * true
 * 
 * Explanation:
 * Both trees have the same structure and the nodes have the same values. 
 * Therefore, the trees are identical.
 * 
 * Sample Input:
 * Tree 1:       1
 *              / \
 *             2   3
 * 
 * Tree 2:       1
 *              / \
 *             3   2
 * 
 * Sample Output:
 * false
 * 
 * Explanation:
 * The trees have the same structure but the values of the nodes are different. 
 * Therefore, the trees are not identical.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(N) where N is the number of nodes in the Binary Tree.
        
    Space Complexity -
        O(N) where N is the number of nodes in the Binary Tree.

*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    bool isIdentical(Node* node1, Node* node2){
        if (!node1 || !node2) {
            return (node1 == node2);
        }

        return (node1->data == node2->data) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
    }
};


int main() {
    // Node1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;
    
    if (solution.isIdentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}