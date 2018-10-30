/*
93. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example
Given binary tree A = {3,9,20,#,#,15,7}, B = {3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        int result = divideConquer(root);
        if (result < 0) return false;
        return true;
    }
    
    // compare if left sub and right sub has the right depth difference
    // then return the depth of this node
    // if unbalanced, return -1
    int divideConquer(TreeNode* root)
    {
        if (root == NULL) return 0;
        
        int hLeft = divideConquer(root->left);
        int hRight = divideConquer(root->right);
        
        if (hLeft == -1 || hRight == -1) return -1;
        if ( abs(hLeft-hRight) > 1) return -1;
        
        return max(hLeft,hRight) + 1;
    }

};