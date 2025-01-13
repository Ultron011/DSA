/**
 * Problem : Flattens a binary tree to a linked list in-place.
 *
 * The function takes the root of a binary tree and flattens it into a linked list in-place.
 * The linked list should use the right pointers to point to the next node in the list and 
 * the left pointers should be set to nullptr.
 *
 * Input:
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 *
 * Output:
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 *
 * Explanation:
 * The binary tree is flattened to a linked list where each node points to the next node in a pre-order traversal.
 */