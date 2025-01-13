/**
 * Problem :  Perform Morris Preorder Traversal of a Binary Tree.
 *
 * This function implements the Morris Preorder Traversal algorithm, which is a way to traverse a binary tree without using any extra space for recursion or a stack. The algorithm modifies the tree during the traversal but restores it to its original state before exiting.
 *
 * Statement : Given the root of a binary tree, perform a preorder traversal using the Morris Traversal technique and return the list of visited nodes.
 *
 * Sample Input :
 *     Tree:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Sample Output :
 *     [1, 2, 4, 5, 3]
 *
 * Explanation :
 *     The preorder traversal visits nodes in the following order: root, left subtree, right subtree.
 *     For the given tree:
 *     - Start at root (1), visit it.
 *     - Move to left child (2), visit it.
 *     - Move to left child (4), visit it.
 *     - No left child, move to right child (5), visit it.
 *     - No children, backtrack to node (2), then to root (1).
 *     - Move to right child (3), visit it.
 *     - No children, traversal complete.
 */