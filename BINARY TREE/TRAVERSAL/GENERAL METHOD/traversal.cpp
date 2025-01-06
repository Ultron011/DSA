/*
    Problem Statement: 
        Given the root of a Binary Tree, return the preorder, inorder and postorder traversal 
        sequence of the given tree by making just one traversal.

    Time complexity - 
        O(3N) where N is the number of nodes in the Binary Tree. Each node is processed once for each traversal type (pre-order, in-order, and post-order)
    
    Space complexity -
         O(4N) where N is the number of nodes in the Binary Tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> preInPostTraversal(Node* root) {
    if (!root) return {};
    vector<int> pre, ino , post;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);

            if (it.first->left) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            ino.push_back(it.first->data);
            it.second = 3;
            st.push(it);

            if (it.first->right) {
                st.push({it.first->right, 1});
            }
        } else {
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> ans = {pre, ino, post};
    return ans;

}

int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}