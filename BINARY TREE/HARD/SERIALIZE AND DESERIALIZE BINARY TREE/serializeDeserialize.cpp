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