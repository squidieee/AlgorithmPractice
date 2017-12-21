/* 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
    /* 
    // depth-first search: recursive
    int minDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        else if (root->left==NULL)
            return minDepth(root->right)+1;
        else if (root->right==NULL)
            return minDepth(root->left) +1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    */
    // breadth-first search: iteratively
    int minDepth(TreeNode* root)
    {
        if (root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int dep(0);
        while(!q.empty())
        {
            dep++;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left==NULL&&node->right==NULL)
                    return dep;
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
        }
        return dep;
    }
};