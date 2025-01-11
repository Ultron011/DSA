/**
 * Problem : Maximum Width of a Binary Tree
 * 
 * Description : Given the root of a binary tree, return the maximum width of the given tree.
 *              The maximum width of a tree is the maximum width among all levels.
 *              The width of one level is defined as the length between the end-nodes 
 *              (the leftmost and rightmost non-null nodes), where the null nodes between 
 *              the end-nodes are also counted into the length calculation.
 * 
 * Input: 
 *        1
 *       / \
 *      3   2
 *     /     \  
 *    5       9 
 *   /         \
 *  6           7
 * 
 * Output: 8
 * 
 * Explanation: The maximum width exists in the fourth level with length 8 (6, null, null, null, null, null, null, 7).
 * 
 */