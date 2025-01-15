#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(log(N)) ,  where N is the number of nodes in the binary search tree.

    Space complexity -
        O(1) 
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) : val(d), left(NULL), right(NULL) {};
};

class Solution {

    public:
        int findFloor(TreeNode* root, int key) {
            int floor = -1;
            while (root) {
                if (root->val == key) {
                    floor = root->val;
                    return floor;
                }

                if (key > root->val) {
                    floor = root->val;
                    root = root->right;
                } else {
                    root = root->left;
                }
            }
            return floor;
        }

};

void printInOrder(TreeNode* root) {
    if (!root) return;

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);

}

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;

    int target = 8;
    int floor = solution.findFloor(root, target);
    
    if(floor != -1){
        cout << "Floor of " << target << " is: " << floor << endl;
    }
    else{
        cout << "No Floor found!";
    }


  return 0;
}