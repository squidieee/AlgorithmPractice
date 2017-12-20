/* 
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        if (root ==NULL)
            return 0;
        if(root->left ==NULL && root->right==NULL)
            return 1;
        int nl = maxDepth(root->left);
        int nr = maxDepth(root->right);
        return max(nl,nr)+1;
    }
};