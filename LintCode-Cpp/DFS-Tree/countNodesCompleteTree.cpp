/*
1317. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Example
Example1

Input: {1,2,3,4,5,6}
Output: 6
Explanation: 
    1
   / \
  2   3
 / \  /
4  5 6
Example2

Input: {1,2,3,4,5,6,8}
Output: 7
Explanation: 
    1
   / \
  2   3
 / \  /\
4  5 6  8
Notice
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

 class Solution {
public:
    /**
     * @param root: root of complete binary tree
     * @return: the number of nodes
     */
    int countNodes(TreeNode * root) {
        if (root == NULL) return 0;
        
        // O(logn)
        int leftH = getHeight(root->left); 
        int rightH = getHeight(root->right); 
        
        int nextCount = leftH == rightH ? countNodes(root->right):countNodes(root->left);
        
        return nextCount + (1 << ( min(leftH, rightH) + 1));
    }
    
    int getHeight(TreeNode * root)
    {
        if (root == NULL) return -1;
        return getHeight(root->left) + 1;
    }
};

// Sol1: brutal force O(n)
// traversal through all nodes to find the total

// Sol2: using height O(logn * logn)
// height of a complete binary tree can be computed by traversal to leftmost node
// subtree of a complete binary tree is also a complete tree
// so we can find any node's height by going leftmost

// for any node,
// if the height of its left subtree is equal to the right subtree
// it means left subtree is full, while right is not
// else left is not full, but right is
// having a full tree means we know its total nodes just by height h: 2^(h+1) - 1
// so we need to go its non-full tree to find its total

// Beacsue we only need to go further from one node on each level, 
// and we need to check the height of two children for that node, cost O(logn)
// the total is O(logn * logn)