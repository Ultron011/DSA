/**
 * Problem: Children Sum Property in a Binary Tree
 * 
 * Problem Statement:
 * Given a binary tree, write a function to check whether the tree satisfies the children sum property. 
 * In a binary tree, the children sum property is defined as:
 * For every node, the value of the node should be equal to the sum of the values of its left and right children.
 * Consider the value of NULL children as 0.
 * 
 * Sample Input:
 *         10
 *        /  \
 *       8    2
 *      / \  / \
 *     3  5 2  0
 * 
 * Sample Output:
 * True
 * 
 * Explanation:
 * - For the root node (10), the sum of its children (8 + 2) is 10.
 * - For the node with value 8, the sum of its children (3 + 5) is 8.
 * - For the node with value 2, the sum of its children (2 + 0) is 2.
 * - For the leaf nodes (3, 5, 2, 0), the children sum property is trivially satisfied as they have no children.
 * 
 * Since all nodes satisfy the children sum property, the output is True.
 */