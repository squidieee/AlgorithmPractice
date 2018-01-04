/* 
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    // Bottom-Up Approach: O(N)
    
    bool isBalanced(TreeNode* root) {
        bool isB = true;
        maxDepth(root, isB);
        return isB;
    }
    int maxDepth(TreeNode* root, bool& isBal) {
        if (root ==NULL)
            return 0;
        int ld = maxDepth(root->left, isBal);
        int rd = maxDepth(root->right, isBal);
        if (abs(ld-rd)>1)
            isBal = false;            
        return max(ld,rd)+1;
    }    
    
};