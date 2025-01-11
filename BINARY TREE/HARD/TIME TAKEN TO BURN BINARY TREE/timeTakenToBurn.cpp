/**
 * Problem : Time taken to burn a binary tree
 * 
 * Description : Given a binary tree and a leaf node from which a fire starts, 
 *              find the minimum time required to burn the entire binary tree. 
 *              The fire spreads to the adjacent nodes (parent and children) 
 *              in 1 unit of time.
 * 
 * Sample Input :
 *          1
 *         / \
 *        2   3
 *       / \
 *      4   5
 * 
 *        leaf = 5
 * 
 * Sample Output :
 *        4
 * 
 * Explanation :
 *        The fire starts at node 5 and spreads as follows:
 *        - Time 1: Node 5 burns.
 *        - Time 2: Node 2 burns.
 *        - Time 3: Node 1 and Node 4 burn.
 *        - Time 4: Node 3 burns.
 *        Therefore, the minimum time required to burn the entire binary tree is 4 units.
 */